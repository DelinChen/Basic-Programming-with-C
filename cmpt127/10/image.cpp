#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <stdio.h>
#include "image.hpp"

Image::Image(){
  cols = 0;
  rows = 0;
  pixels = NULL;
  }

Image::~Image(){
  if (pixels!=NULL)
  {
    delete[] pixels;
  }
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
  delete[] pixels;
  uint8_t pixels[width*height];
  if (pixels == NULL)
  {
    return 1;
  }
  for (int i = 0; i < width*height; ++i)
  {
    pixels[i] = fillcolour;
  }
  return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
  if (x>=cols||y>=rows)
  {
    return 1;
  }
  pixels[y*cols+x] = colour;
  return 0;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
  if (x>=cols||y>=rows||colourp == NULL)
  {
    return 1;
  }
  *colourp = pixels[y*cols+x];
  return 0;
}
