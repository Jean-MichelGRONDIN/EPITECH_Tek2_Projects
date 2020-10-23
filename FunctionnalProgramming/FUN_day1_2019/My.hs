mySucc :: Int -> Int
mySucc x = x+1


myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True
    | otherwise = False


myAbs :: Int -> Int
myAbs x
    | x < 0 = x * (-1)
    | otherwise = x


myMin :: Int -> Int -> Int
myMin x y
    | x < y = x
    | otherwise = y


myMax :: Int -> Int -> Int
myMax x y
    | x > y = x
    | otherwise = y


myTuple :: a -> b -> (a, b)
myTuple a b = (a,b)


myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a,b,c)


myFst :: (a, b) -> a
myFst (a,b) = a


mySnd :: (a, b) -> b
mySnd (a,b) = b


mySwap :: (a, b) -> (b, a)
mySwap (a,b) = (b,a)


myHead :: [a] -> a
myHead [] = error "empty list"
myHead (a:as) = a


myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (x:xs) = xs


myLength :: [a] -> Int
myLength [] = 0
myLength (a:as) = 1 + myLength as


myNth :: [a] -> Int -> a
myNth [] i = error "index too large"
myNth a 0 = myHead a
myNth a i
      | i < 0 = error "index negative"
      | otherwise = myNth (myTail(a)) (i - 1)


myTake :: Int -> [a] -> [a]
myTake 0 a = []
myTake i [] = []
myTake i a
       | i < 0 = error "index is negative"
       | otherwise = myHead a:myTake (i - 1) (myTail(a))


myDrop :: Int -> [a] -> [a]
myDrop 0 a = a
myDrop i [] = []
myDrop i a
       | i < 0 = error "index is negative"
       | otherwise = myDrop (i - 1) (myTail a)


myAppend :: [a] -> [a] -> [a]
myAppend a [] = a
myAppend [] b = b
myAppend a b = myHead a:myAppend (myTail a) b


myReverse :: [a] -> [a]
myReverse [] = []
myReverse a = myAppend (myReverse (myTail a)) (myHead a:[])


myInit :: [a] -> [a]
myInit [] = error "empty list"
myInit a
       | myLength a == 1 = []
       | otherwise = myHead a:myInit (myTail a)


myLast :: [a] -> a
myLast [] = error "empty list"
myLast a
       | myLength a == 1 = myHead a
       | otherwise = myLast (myTail a)


myZip :: [a] -> [b] -> [(a, b)]
myZip a [] = []
myZip [] b = []
myZip a b = myTuple (myHead a) (myHead b):myZip (myTail a) (myTail b)


myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([],[])
myUnzip a = (myFst (myHead a):myFst (myUnzip (myTail a)), mySnd (myHead a):mySnd (myUnzip (myTail a)))


myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f a = f (myHead a):myMap f (myTail a)


myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f a
         | f (myHead a) == True = myHead a:myFilter f (myTail a)
         | otherwise = myFilter f (myTail a)


myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f b a
        | myLength a == 1 = f b (myHead a)
        | otherwise = myFoldl f (f b (myHead a)) (myTail a)


myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f b a
        | myLength a == 1 = f (myLast a) b
        | otherwise = myFoldr f (f (myLast a) b) (myInit a)


myFilterFalse :: (a -> Bool) -> [a] -> [a]
myFilterFalse f [] = []
myFilterFalse f a
         | f (myHead a) == False = myHead a:myFilterFalse f (myTail a)
         | otherwise = myFilterFalse f (myTail a)


mySpan :: (a -> Bool) -> [a] -> ([a], [a])
mySpan f a = (myFilter f a, myFilterFalse f a)


myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort f a
            | myLength a == 1 = a
            | f (myHead a) (myHead(myTail a)) == True = myHead a:myQuickSort f (myTail a)
            | otherwise = myQuickSort f (myQuickSort f (myHead (myTail a):myHead a:myTail (myTail a)))