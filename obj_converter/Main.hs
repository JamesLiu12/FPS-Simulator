module Main where

import System.Directory (getDirectoryContents, doesDirectoryExist)
import Data.Bifunctor (second)
import Data.List (isSuffixOf)
import Data.Char (toLower)
import Control.Monad (when, unless)

import Obj
import CDump

process :: [String] -> [String] -> [(String, String)]
process objNames raws = zip
    objNames
    (((uncurry dumpObjToC <$>) . (second parseObj <$>)) (zip objNames raws))

main = do
    assetsFolderExists <- doesDirectoryExist "./obj"
    outFolderExists <- doesDirectoryExist "./out"
    if not assetsFolderExists || not outFolderExists then do
        unless assetsFolderExists $
            putStrLn "\"obj\" folder does not exists."
        unless outFolderExists $
            putStrLn "\"out\" folder does not exists."
    else do
        paths <- getDirectoryContents "./obj"
        let objPaths :: [String] = filter (isSuffixOf ".obj" . map toLower) paths
        raws <- mapM readFile (("./obj/"++) <$> objPaths)
        let objNames = (\name -> take (length name - 4) name) <$> objPaths
            namesAndDumpedC = process objNames raws
        mapM_ (\(name, dumpedC) -> writeFile ("./out/" ++ name ++ ".c") dumpedC) namesAndDumpedC
