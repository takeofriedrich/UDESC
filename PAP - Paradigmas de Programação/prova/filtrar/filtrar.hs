filtrar :: (a-> Bool) -> [a] -> [a]
filtrar pred [] = []
filtrar pred (x:xs) = if pred x then x : filtrar pred xs else filtrar pred xs

verificaImpar :: Int -> Bool
verificaImpar n = (n `mod` 2) == 1

main :: IO ()
main = do
    print $ filtrar verificaImpar [1,2,3,4,5,6,7,8,9]