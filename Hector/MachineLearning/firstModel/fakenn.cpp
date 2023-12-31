#define NN_IMPLEMENTATION
#include "nn.h"
#define OLIVEC_IMPLEMENTATION
#include"olive.cpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define IMG_WIDTH 800
#define IMG_HEIGHT 600

uint32_t img_pixels[IMG_WIDTH*IMG_HEIGHT];

int main()
{
  srand(time(0));
  size_t arch[] = {2,2,1};
  NN nn = nn_alloc(arch, ARRAY_LEN(arch));
  nn_rand(nn,0,1);
  NN_PRINT(nn);

  Olivec_Canvas img = olivec_canvas(img_pixels, IMG_WIDTH,IMG_HEIGHT,IMG_WIDTH);
  olivec_fill(img, 0xFF0000FF);
  const char *img_path = "nn.png";
  if(!stbi_write_png(img_path,img.width,img.height,4,img.pixels,img.stride*sizeof(uint32_t))){
    printf("ERORO");
    return 1;
  }
  printf("saved");
  return 0;
}
