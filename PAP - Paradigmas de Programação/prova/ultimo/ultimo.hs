inverso :: [a] -> [a]
inverso [] = []
inverso xs = last xs : inverso (init xs)

primeiroElemento :: [a] -> a
primeiroElemento [] = error "lista nao pode ser vazia"
primeiroElemento (x:xs) = x

ultimoElemento :: [a] -> a
ultimoElemento [] = error "lista nao pode ser vazia"
ultimoElemento xs = primeiroElemento (inverso xs)


main :: IO ()
main = do
    print $ ultimoElemento [99]