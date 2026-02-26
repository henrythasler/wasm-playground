#include <stdint.h>
extern int write_png(const char *filename, int w, int h, int comp, const void *dataPtr, int stride_in_bytes);

#define RGB 3
#define RGBA 4

#define WIDTH 243
#define HEIGHT WIDTH
#define COLOR_DEPTH RGB

static unsigned char buffer[WIDTH * HEIGHT * RGB];

// // 16.16 fixed-point format
// #define SHIFT 16
// #define SCALE 0x10000
// typedef int64_t fixed;

// // mandelbrot settings
// #define xmin -163840 // -2.5f
// #define xmax 0x10000 // 1f
// #define ymin -0x10000 // -1f
// #define ymax 0x10000 // 1f

// #define dx 573  // (xmax - xmin) / width;
// #define dy 327  // (ymax - ymin) / height;

// Fixed-point multiply
// fixed mul(fixed a, fixed b) {
//     // return ((int64_t)a * (int64_t)b) / SCALE;
//     return (a * b) / SCALE;
// }

// int mandelbrot(fixed cx, fixed cy, int max_iter) {
//     fixed x = 0, y = 0;
//     fixed xx, yy;

//     for (int i = 0; i < max_iter; i++) {
//         xx = mul(x, x);
//         yy = mul(y, y);

//         if (xx + yy > (4*SCALE)) {
//             return i;
//         }

//         y = (mul(x, y) * 2) + cy;
//         x = xx - yy + cx;
//     }
//     return max_iter;
// }

// Check if a point should be filled in the Sierpinski carpet
int32_t is_filled(int32_t x, int32_t y) {
    while (x > 0 || y > 0) {
        // Get the lowest base-3 digit without using modulus
        // Method: subtract multiples of 3 until we get 0, 1, or 2
        int x_digit = x - (x / 3) * 3;
        int y_digit = y - (y / 3) * 3;
        
        // If both digits are 1, it's a hole
        if (x_digit == 1 && y_digit == 1) {
            return 0;
        }
        
        x /= 3;
        y /= 3;
    }
  return 0xff;
}

int _start() {
  for (int32_t y = 0; y < HEIGHT; y++) {
    // fixed cy = ymin + y * dy;
    for (int32_t x = 0; x < WIDTH; x++) {
      // fixed cx = xmin + x * dx;
      // int iter = mandelbrot(cx, cy, 0xff);
      int32_t color = is_filled(x, y);
      buffer[(y * WIDTH + x) * RGB] = color;
      buffer[(y * WIDTH + x) * RGB + 1] = color;
      buffer[(y * WIDTH + x) * RGB + 2] = color;
    }
  }
  return write_png("fractal.png", WIDTH, HEIGHT, COLOR_DEPTH, buffer, WIDTH * COLOR_DEPTH);
}