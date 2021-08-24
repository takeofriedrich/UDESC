infinita :: [Int]
infinita = 1 : infinita

main :: IO ()
main = do
    print $ infinita