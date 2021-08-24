import Data.Char

intToString :: Int -> String
intToString 0 = []
intToString x = intToDigit (x `mod` 10) : intToString (x `div` 10)

-- intToString 1095 = 
-- '5' : intToString 109 =
-- '5' : '9' : intToString 10 =
-- '5' : '9' : '1' : intToString 0 =
-- '5' : '9' : '1' : '0' 

reverte :: String -> String
reverte [] = []
reverte x = last x : reverte (init x)


-- converte :: [Int] -> [String]
converte [] = []
converte (x:xs) = reverte (intToString x) : converte xs


main :: IO ()
main = do
    -- print $ mod 10 3
    -- print $ floor 1.7
    -- print $ reverte (intToString 1094)
    print $ converte [1094,4096,24,1]
