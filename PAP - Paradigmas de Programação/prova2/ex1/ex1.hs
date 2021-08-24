primeiro :: (a -> Bool) -> [a] -> Maybe a

-- primeiro odd [4,5,6]
-- primeiro odd [5,6]
-- 5

-- primeiro odd [4,6,8]
-- primeiro odd [6,8]
-- primeiro odd [8]
-- primeiro odd []
-- Nothing

primeiro f [] = Nothing
primeiro f (x:xs) = if f(x) then Just x else primeiro f xs

main :: IO ()
main = do
    print $ primeiro odd [2,8,4]
    print $ primeiro odd [2,3,4]