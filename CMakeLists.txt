cmake_minimum_required(VERSION 3.24)
project(FPS_Simulator C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS_RELEASE "-O2")

add_executable(
        FPS_Simulator

        main.c


        Game/models/boundaries.h
        Game/models/boundaries.c
        Game/models/cube.h
        Game/models/cube.c
        Game/models/enemy_body.h
        Game/models/enemy_body.c
        Game/models/enemy_head.h
        Game/models/enemy_head.c
        Game/models/enemy_leg.h
        Game/models/enemy_leg.c
        Game/models/floor.h
        Game/models/floor.c
        Game/models/wall.h
        Game/models/wall.c
        Game/models/models.h

        Game/scene.h
        Game/scene.c
        Game/player.h
        Game/player.c
        Game/enemy.h
        Game/enemy.c
        Game/runner.h
        Game/runner.c
        Game/game.h

        op_engine/canvas.h
        op_engine/canvas.c
        op_engine/transform.h
        op_engine/transform.c
        op_engine/matrix.h
        op_engine/matrix.c
        op_engine/vector.h
        op_engine/vector.c
        op_engine/mesh.h
        op_engine/mesh.c
        op_engine/triangle.h
        op_engine/triangle.c
        op_engine/line.h
        op_engine/line.c
        op_engine/plane.h
        op_engine/plane.c
        op_engine/segment.h
        op_engine/segment.c
        op_engine/object.h
        op_engine/object.c
        op_engine/tag.h
        op_engine/collide_box.c
        op_engine/collide_box.h
        op_engine/input.h
        op_engine/input.c
        util/util.c
        util/util.h
        util/array_list.c
        util/array_list.h

    GameUI/Game_UI.h
    GameUI/ui_startmenu.h
    GameUI/ui_startmenu.c
    GameUI/ui_settingmenu.h
    GameUI/ui_settingmenu.c
    GameUI/ui_defeatmenu.h
    GameUI/ui_defeatmenu.c
    playground.h
)
target_link_libraries(FPS_Simulator m)