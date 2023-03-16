module Obj (parseObj, Obj(..), Vertex, Triangle) where

import Control.Arrow ((>>>))
import Data.List (isPrefixOf)

type Vertex = (Double, Double, Double)
type Triangle = (Int, Int, Int)

data Obj = Obj {
        vertices :: [Vertex],
        triangles :: [Triangle]
    } deriving Show

keepLine :: String -> Bool
keepLine line = any (\f -> f line) (isPrefixOf <$> ["f ", "v "])

getVertices :: [[String]] -> [Vertex]
getVertices =
    filter ((=="v") . head) >>>
    map getVertex
    where
        getVertex [_, xRaw, yRaw, zRaw] = (read xRaw, read yRaw, read zRaw)

getFaces :: [[String]] -> [Triangle]
getFaces = 
    filter ((=="f") . head) >>>
    map getFace
    where
        getFace [_, v1, v2, v3] = (getVertexIndex v1, getVertexIndex v2, getVertexIndex v3)
        getVertexIndex :: String -> Int
        getVertexIndex = read . takeWhile (/='/')

parseObj :: String -> Obj
parseObj = 
        lines
    >>> filter keepLine
    >>> map words
    >>> (\records -> Obj {
            vertices = getVertices records,
            triangles = getFaces records})
