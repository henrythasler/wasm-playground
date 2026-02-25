extern int write_png(const char *filename, int w, int h, int comp, const void *dataPtr, int stride_in_bytes);

#define RGB 3
#define RGBA 4

#define WIDTH 400
#define HEIGHT 400
#define COLOR_DEPTH RGB

static unsigned char buffer[WIDTH * HEIGHT * RGB];

int _start() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      buffer[(y * WIDTH + x) * RGB] = 0x7f;
      buffer[(y * WIDTH + x) * RGB + 1] = 0x3f;
      buffer[(y * WIDTH + x) * RGB + 2] = 0x7f;
    }
  }
  return write_png("fractal.png", WIDTH, HEIGHT, COLOR_DEPTH, buffer, WIDTH * COLOR_DEPTH);
}