extern int write_png(const char *filename, int w, int h, int comp, const void *dataPtr, int stride_in_bytes);

#define RGB 3
#define RGBA 4

#define WIDTH 640
#define HEIGHT 480
#define COLOR_DEPTH RGB

static unsigned char buffer[WIDTH * HEIGHT * 3];

int _start() {
  for (int cnt = 1000; cnt > 0; cnt--) {
    buffer[cnt * 3] = 0xff;
    buffer[cnt * 3 + 1] = 0x7f;
    // buffer[x * 3 + 2] = (unsigned char)x;
  }
  // buffer[WIDTH * HEIGHT * 3 - 1] = 0xff;
  // for (int y = 0; y < HEIGHT; y++) {
  //   for (int x = 0; x < WIDTH; x++) {
  //     buffer[y * WIDTH + x] = 0xff;
  //     buffer[y * WIDTH + x + 1] = 0xff;
  //     buffer[y * WIDTH + x + 2] = 0;
  //   }
  // }
  // return cnt;
  return write_png("test.png", WIDTH, HEIGHT, COLOR_DEPTH, buffer, WIDTH * COLOR_DEPTH);
}