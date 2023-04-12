module CDump where

import Obj
import Data.List (intercalate)
import Data.Char (toLower, toUpper)
import GHC.Num (Integer(IN))

cDumpFileTemplate :: String -> [Vertex] -> [Triangle] -> String
cDumpFileTemplate modelName vertices triangles = 
    let upperModelName = toUpper (head modelName) : tail modelName
        lowerModelName = map toLower modelName
        dumpVertices = do
            (i, vertex) <- zip [0..] vertices
            ["\t" ++ vertexTemplate lowerModelName i vertex]
        dumpTriangles = do
            (i, triangle) <- zip [0..] triangles
            ["\t" ++ triangleTemplate lowerModelName i triangle]
        in
    intercalate "\n" ([
        "#include \"../mesh.h\"",
        "",
        "void Model" ++ upperModelName ++
        "_Init(struct Mesh *" ++ lowerModelName ++ ") {"
        ] ++ dumpVertices ++ [""] ++ dumpTriangles ++
        ["}",
        "",
        "struct Mesh* Model" ++ upperModelName ++ "_New() {",
        "\tstruct Mesh *" ++ lowerModelName ++
        "= New_Mesh(" ++ show(length triangles) ++
        ", " ++ show(length vertices) ++ ");",
        "\tModel" ++ upperModelName ++ "_Init(" ++ lowerModelName ++ ");",
        "\treturn " ++ lowerModelName ++ ";",
        "}",
        ""]
    )

vertexTemplate :: String -> Int -> Vertex -> String
vertexTemplate pointer index (x, y, z) =
    "Vector3_Set(&" ++ pointer ++
    "->vertices[" ++ show index ++
    "], " ++ show x ++ ", " ++ show y ++ ", " ++ show z ++ ");"

triangleTemplate :: String -> Int -> Triangle -> String
triangleTemplate pointer index (v1, v2, v3) =
    "Face_Set(&" ++ pointer ++
    "->triangles[" ++ show index ++
    "], " ++ show v1 ++ ", " ++ show v2 ++ ", " ++ show v3 ++ ");" 

dumpObjToC :: String -> Obj -> String
dumpObjToC name (Obj vertices triangles) =
    cDumpFileTemplate name vertices triangles
