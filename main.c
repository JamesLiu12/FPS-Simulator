#pragma once
#include <stdio.h>

#include "op_engine/canvas.h"

int main() {
    struct Canvas* canvas = new_canvas(3, 3);
    canvas->vram_green[4] = 255;
    clear();
    for(int i = 0; i < 3 * 60; i++){
        canvas_flush(canvas);
    }
    del_canvas(canvas);
    return 0;
}
