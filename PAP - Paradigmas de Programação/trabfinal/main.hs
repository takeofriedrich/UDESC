import Text.ParserCombinators.Parsec

data Type = TypeInt
          | TypeVar Name
          | TypeArrow Type Type
          deriving Show

type Name = String

type Unifier = [(Name, Type)]

parserType :: Parser Type
parserType =
  try parserAtom
  -- <|> typeArrow

parserAtom :: Parser Type
parserAtom = 
  try parserInt <|> parserVar -- <|> parserParen

parserInt :: Parser Type
parserInt = do
  string "Int"
  return (TypeInt)

parserVar :: Parser Type
parserVar = do
  name <- many1 lower
  return (TypeVar name)

--parserFun :: Parser Type
--parserFun = do
  --name <- many1 letter
  --string "->"
  --remain <- many1 letter
  --return (TypeArrow (parserAtom name) (parserType remain))

unify :: Type -> Type -> Maybe Unifier

-- Regra: Duas variaveis iguais se unificam:
--
--   ---------------- (REFL)
--      a ~ a = {}
unify (TypeVar x) (TypeVar y) | x == y =
  Just []

-- Regra: dois Int se unificam:
--
--   ---------------- (Int)
--    Int ~ Int = {}
unify TypeInt TypeInt = 
  Just []

-- Regra: variável na esquerda!
--     A não aparece em b
--   ---------------------- (LEFT)
--     a ~ b = { a |-> b }
unify (TypeVar a) b =
  if occursCheck a b then
    Nothing
  else
    -- Troque a por b!
    Just [(a, b)]

-- Regra: variável na esquerda!
--     A não aparece em b
--   ---------------------- (RIGHT)
--     b ~ a = { a |-> b}
unify a (TypeVar b) =
  if occursCheck b a then
    Nothing
  else
    -- Troque b por a!
    Just [(b, a)]

-- Não podemos unificar
unify _ _ =
  Nothing


occursCheck :: Name -> Type -> Bool
-- Verifica se o TypeVar X existe no TypeInt 
occursCheck x (TypeInt) =
  False -- É impossível

-- Verifica se o TypeVar X existe no TypeVar Y
occursCheck x (TypeVar y) =
  x == y -- Apenas se forem iguais!

-- Verifica se o TypeVar X existe no TypeArrow (FALTA FAZERRRR)




main :: IO ()
main = do 
  putStrLn "Digite um termo:"
  a <- getLine
  
  let Right term_a = parse parserType "<stdin>" a
  putStrLn "Digite outro termo:"
  --Lê uma linha extra...

  b <- getLine
  let Right term_b = parse parserType "<stdin>" b

  putStrLn "Unificacao:"
  print term_a
  print term_b
  print $ unify term_a term_b
