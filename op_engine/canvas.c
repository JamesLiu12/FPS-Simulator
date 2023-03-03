#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "canvas.h"

/*
 This is the definition of canvas.
 The reason of using 1D array instead of 2D for storing display RAM is to reduce the indexing times.
*/
struct Canvas* new_canvas(short height, short width){
    struct Canvas* canvas = malloc(sizeof(struct Canvas));

    canvas->height = height;
    canvas->width = width;

    int vram_size = height * width * (int)sizeof(int);
    int depth_size = height * width * (int)sizeof(double);

    canvas->vram_red = malloc(vram_size);
    canvas->vram_green = malloc(vram_size);
    canvas->vram_blue = malloc(vram_size);
    canvas->vram_depth = malloc(depth_size);

    memset(canvas->vram_red, 0, vram_size);
    memset(canvas->vram_green, 0, vram_size);
    memset(canvas->vram_blue, 0, vram_size);
    memset(canvas->vram_depth, 0, depth_size);

    return canvas;
}

/*
 Freeing the memory of canvas.
 */
void del_canvas(struct Canvas* canvas){
    free(canvas->vram_red);
    free(canvas->vram_green);
    free(canvas->vram_blue);
    free(canvas);
}

/*
 Displaying the current frame.
 */
void canvas_flush(struct Canvas* canvas){
    move_cursor_top_left();

    register int height, width, vram_index;

    for (height = 0; height < canvas->height; height++) {
        for (width = 0; width < canvas->width; width++) {
            vram_index = height * canvas->width + width;
            printf("\x1b[38;2;%d;%d;%dm",
                   canvas->vram_red[vram_index],
                   canvas->vram_green[vram_index],
                   canvas->vram_blue[vram_index]);
            printf("██");
        }
        puts("");
    }
}

//clear the terminal
void clear() {
    printf("\033[2J");
}

// Move the cursor to the top-left corner
void move_cursor_top_left() {
    printf("\033[1;1H");
}