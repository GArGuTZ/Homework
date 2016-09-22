data BinarySearchTree a = Null
                        | Branch (BinarySearchTree a) a (BinarySearchTree a) 
                        deriving (Eq, Show)

insert :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
insert Null x = Branch Null x Null
insert b@(Branch left x right) y | x < y = Branch left x (insert right y)
                                 | x > y = Branch (insert left y) x right
                                 | otherwise = b
                             
delete :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
delete Null _ = Null
delete b@(Branch left x right) y | x < y = Branch left x (delete right y)
                                 | x > y = Branch (delete left y) x right
                                 | otherwise = delete' b
                                 where delete' (Branch Null _ Null) = Null
                                       delete' (Branch Null _ right) = right
                                       delete' (Branch left _ Null) = left
                                       delete' (Branch left _ right) = Branch left (leftChild right) (delete right (leftChild right))
                                                                     where leftChild (Branch Null x _) = x
                                                                           leftChild (Branch left _ _) = leftChild left

search :: (Ord a) => BinarySearchTree a -> a -> Bool
search Null _ = False
search (Branch left x right) y | x < y = search right y
                               | x > y = search left y
                               | otherwise = True

size :: BinarySearchTree a -> Int
size Null = 0
size (Branch left _ right) = (size left) + 1 + (size right)

height :: BinarySearchTree a -> Int
height Null = 0
height (Branch left _ right) = max (height left) (height right) + 1