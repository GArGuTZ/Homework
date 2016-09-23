import Control.Monad
import Control.Monad.Writer
import Data.List

data Edge = Edge { start :: Int,
                   end :: Int,
                   price :: Int }

instance Show Edge where
    show (Edge start end _) = show start ++ "->" ++ show end

data Vertex = Vertex { number :: Int,
                       label :: Maybe (Writer [Edge] Int) }

instance Eq Vertex where
    (==) x y = number x == number y

instance Ord Vertex where
    compare (Vertex _ Nothing) (Vertex _ Nothing) = EQ
    compare (Vertex _ Nothing) (Vertex _ (Just _)) = GT
    compare (Vertex _ (Just _)) (Vertex _ Nothing) = LT
    compare (Vertex _ (Just x)) (Vertex _ (Just y)) = compare (fst (runWriter x)) (fst (runWriter y))
    
instance Show Vertex where
    show (Vertex x Nothing) = "(Vertice " ++ show x ++ ": no path)"
    show (Vertex x (Just y)) = "(Vertice " ++ show x ++ ": Distance " ++ show (fst (runWriter y))++ ", Path: " ++ show (snd (runWriter y)) ++ ")"

data Graph = Graph { vertices :: [Vertex],
                     edges :: [Edge] } deriving Show

findEdge :: [Edge] -> Int -> Int -> Maybe Edge
findEdge [] _ _ = Nothing
findEdge (x : xs) s e | s == (start x) && e == (end x) = Just x
                      | otherwise = findEdge xs s e

addEdge :: Maybe (Writer [Edge] Int) -> Maybe Edge -> Maybe (Writer [Edge] Int)
addEdge Nothing Nothing = Nothing
addEdge Nothing (Just _) = Nothing
addEdge (Just _) Nothing = Nothing
addEdge (Just x) (Just y) = Just (addEdge' x y)

addEdge' :: Writer [Edge] Int -> Edge -> Writer [Edge] Int
addEdge' x y = do
    newPrice <- x
    tell (y : [])
    return (newPrice + (price y))

dijkstra :: Graph -> [Vertex]
dijkstra (Graph v e) = dijkstra' [] v
                       where dijkstra' visited [] = visited
                             dijkstra' visited rest = dijkstra' newVisited newRest
                                                    where newVisited = (minimum rest) : visited
                                                          newRest = delete (minimum rest) (map (update (minimum rest)) rest)
                                                          update x y = min (Vertex (number y) (addEdge (label x) (findEdge e (number x) (number y)))) y

graph = Graph [(Vertex 1 (Just (writer (0, [])))), (Vertex 2 Nothing), (Vertex 3 Nothing), (Vertex 4 Nothing), (Vertex 5 Nothing)] [(Edge 1 3 1), (Edge 1 4 2), (Edge 4 1 2), (Edge 2 3 3), (Edge 3 2 3), (Edge 3 4 4), (Edge 4 3 4), (Edge 4 2 5), (Edge 5 4 1)]