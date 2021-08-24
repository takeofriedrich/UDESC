data Tree a = Leaf
            | Branch (Tree a) a (Tree a) deriving Show

atravessar :: (a -> b) -> Tree a -> Tree b
atravessar f arvore = 

main :: IO ()
main = do
    print $ "Hello World"