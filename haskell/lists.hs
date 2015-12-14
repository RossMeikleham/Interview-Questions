
-- Reverse linked list
reverse_list :: [a] -> [a]
reverse_list [] = []
reverse_list (x::xs) = (reverse_list xs) ++ [x]


