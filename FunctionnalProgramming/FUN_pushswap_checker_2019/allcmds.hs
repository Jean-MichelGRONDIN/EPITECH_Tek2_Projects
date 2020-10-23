module AllCmds where

sa :: ([Int],[Int]) -> ([Int],[Int])
sa ([],b) = ([], b)
sa (a,b)
    | length a < 2 = (a,b)
    | otherwise = (head (tail a):head a:drop 2 a,b)

sb :: ([Int],[Int]) -> ([Int],[Int])
sb (a,[]) = (a, [])
sb (a,b)
    | length b < 2 = (a,b)
    | otherwise = (a,head (tail b):head b:drop 2 b)

sc :: ([Int],[Int]) -> ([Int],[Int])
sc tabs = sa (sb tabs)

pa :: ([Int],[Int]) -> ([Int],[Int])
pa (a,[]) = (a,[])
pa (a,b) = (head b:a,drop 1 b)

pb :: ([Int],[Int]) -> ([Int],[Int])
pb ([],b) = ([],b)
pb (a,b) = (drop 1 a,head a:b)

ra :: ([Int],[Int]) -> ([Int],[Int])
ra ([],b) = ([],b)
ra (a,b) = (reverse (head a:reverse (fst (drop 1 a,b))),b)

rb :: ([Int],[Int]) -> ([Int],[Int])
rb (a,[]) = (a,[])
rb (a,b) = (a,reverse (head b:reverse (snd (a,drop 1 b))))

rr :: ([Int],[Int]) -> ([Int],[Int])
rr tabs = ra (rb tabs)

rra :: ([Int],[Int]) -> ([Int],[Int])
rra ([],b) = ([],b)
rra (a,b) = (head (reverse a):reverse (drop 1 (reverse a)),b)

rrb :: ([Int],[Int]) -> ([Int],[Int])
rrb (a,[]) = (a,[])
rrb (a,b) = (a,head (reverse b):reverse (drop 1 (reverse b)))

rrr :: ([Int],[Int]) -> ([Int],[Int])
rrr tabs = rra (rrb tabs)