busca ::  Ord a => a -> [a] -> a
busca a [] = a
busca a (x:xs) = if x > a then busca x xs else busca a xs

maiorValor :: Ord a => [a] -> a
maiorValor (x:xs) = busca x xs

main :: IO ()
main = do
    print $ busca 1 [99,7,4,2,88,2,1,120]