concatenacao :: [a] -> [a] -> [a]
-- Caso base
concatenacao [] ys = ys
-- Caso recursivo
concatenacao (x : xs) ys = x : concatenacao xs ys

contains :: Eq a => a -> [a] -> Bool
-- contains 3 [1,2,3]
-- 3 [2,3]
-- 3 [3]
-- True

-- caso base
contains a [] = False
contains a (x : xs) =
  if (a == x)
    then True
    else contains a xs

intersecao :: Eq a => [a] -> [a] -> [a]
-- intersecao [1,2,3] [2,3,4]
-- intersecao [2,3] [2,3,4]
-- 2 : intersecao [3] [2,3,4]
-- 2 : 3 : intersecao [] [2,3,4]
-- [2,3]
intersecao [] ys = []
intersecao xs [] = []
intersecao (x : xs) ys =
  if contains x ys
    then x : intersecao xs ys
    else intersecao xs ys

inverso :: [a] -> [a]
-- [4,3,2,1]
-- inverso [4,3,2,1]
-- inverso 4 : [3,2,1]
-- inverso 4 : 3 : [2,1]
-- inverso 4 : 3 : 2 : [1]
-- [1,2,3,4]

inverso [] = []
inverso xs = last xs : inverso (init xs)

primeiros :: Int -> [a] -> [a]
-- primeiros 2 [1,2,3,4,5]
-- 1 : primeiros 1 [2,3,4,5]
-- 1 : 2 : primeiros 0 [3,4,5]
-- [1,2]
primeiros 0 xs = []
primeiros x (y : ys) = y : primeiros (x -1) ys

ultimos :: Int -> [a] -> [a]
ultimos x ys = inverso (primeiros x (inverso ys))

binParaInt :: String -> Integer
binParaInt "0" = 0
binParaInt "1" = 1
binParaInt ('0' : xs) = binParaInt xs
binParaInt ('1' : xs) = 2 ^ (length xs) + binParaInt xs
binParaInt xs = error "Valor não representa um número binario"

intParaBin :: Integer -> String
intParaBin i =
  reverse (aux i)
  where
    aux :: Integer -> String
    aux i =
      let divisao = i `div` 2
       in if divisao > 0
            then
              if i `mod` 2 == 0
                then '0' : aux divisao
                else '1' : aux divisao
            else -- um caracter

              if i `mod` 2 == 0
                then "0"
                else "1"

busca :: Int -> [Int] -> Int
busca a [] = a
busca a (x : xs) = if x < a then busca x xs else busca a xs

menorValor :: [Int] -> Int
menorValor xs = busca 9999 xs

removerPrimeiro :: Eq a => [a] -> a -> [a]
removerPrimeiro [] x = []
removerPrimeiro (y : ys) x = if x == y then removerPrimeiro ys x else y : removerPrimeiro ys x

ordenar :: [Int] -> [Int]
ordenar [] = []
ordenar (x : xs) = (menorValor xs) : concatenacao (removerPrimeiro (ordenar (removerPrimeiro xs (menorValor xs))) (menorValor xs)) [x]

dobrarDir :: (a -> b -> b) -> b -> [a] -> b
dobrarDir f x [] = x

-- dobrarDir f x (y : ys) = f (x y) : (dobrarDir f x ys)

filtrar :: (a -> Bool) -> [a] -> [a]
filtrar pred [] = []
filtrar pred (x : xs) = if pred x then x : filtrar pred xs else filtrar pred xs

verificaImpar :: Int -> Bool
verificaImpar n = (n `mod` 2) == 1

impares :: [Int] -> [Int]
impares x = filter verificaImpar x

mapear :: (a -> b) -> [a] -> [b]
mapear x [] = []
mapear x (y : ys) = x y : mapear x ys