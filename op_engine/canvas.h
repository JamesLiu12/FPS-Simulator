//Canvas for displaying
struct Canvas {
    short height, width;
    int *vram_red, *vram_green, *vram_blue;
    double *vram_depth;
};

struct Canvas* new_canvas(short height, short width);
void del_canvas(struct Canvas* canvas);

void canvas_flush(struct Canvas* canvas);
void clear();
void move_cursor_top_left();
