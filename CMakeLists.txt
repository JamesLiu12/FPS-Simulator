cmake_minimum_required(VERSION 3.24)
project(FPS_Simulator C)

set(CMAKE_C_STANDARD 17)

add_executable(
    FPS_Simulator

    main.c

    op_engine/op_engine.h
    op_engine/canvas.c
    op_engine/canvas.h
    op_engine/matrix.c
    op_engine/matrix.h
    op_engine/triangle.h
    op_engine/vector.c
    op_engine/vector.h
    op_engine/matrix.c
    op_engine/mesh.h
    op_engine/collide_box.h
    op_engine/scene.h
        op_engine/triangle.c

    op_engine/models/cube.c

    util/util.h
    util/util.c
        op_engine/transform.c op_engine/mesh.c op_engine/line.h op_engine/plane.h op_engine/segment.h op_engine/segment.c op_engine/plane.c op_engine/line.c)
