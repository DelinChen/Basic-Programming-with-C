#include <iostream>
#include <fstream>
#include <stdint.h> 
#include <stdlib.h>
#include <stdio.h>
#include "image3.hpp"

using namespace std;
Image::Image(){
  cols = 0;
  rows = 0;
  pixels = NULL;
  }

Image::~Image(){
  if (pixels!=NULL){
    for (int i = 0; i < rows; ++i)
    {
      delete[] pixels[i];
    }
    delete[] pixels;
  }
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
  if (pixels!=NULL){
    for (int i = 0; i < rows; ++i)
    {
      delete[] pixels[i];
    }
    delete[] pixels;
  }
  pixels = new uint8_t*[height];
  for(int i = 0; i < height; i++){
      pixels[i] = new uint8_t[width];
  }   
  if (pixels == NULL){
    return 1;
  }
  cols = width;
  rows = height;
  for (int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < cols ; j++){
      pixels[i][j] = fillcolour;
    }
  }
  return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
  if (x>=cols||y>=rows)
  {
    return 1;
  }
  pixels[y][x] = colour;
  return 0;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
  if (x>=cols||y>=rows||colourp == NULL||pixels == NULL)
  {
    return 1;
  }
  *colourp = pixels[y][x];
  return 0;
}

int Image::save( const char* filename ){
  if (filename == NULL){
    return 1;
  }
  fstream fp;
  fp.open(filename, fstream::out);
  if (!fp.is_open()||(rows == 0 && cols > 0) || (rows > 0 && cols == 0)){
    return 1;
  }
  if (rows == 0&& cols == 0){
    fp.close();
    return 0;
  }
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      fp<<(int)pixels[i][j]<<" ";
    }
    fp<<endl;
  }
  fp.close();
  return 0;
}

int Image::load( const char* filename ){
  if (filename == NULL){
    return 1;
  }
  fstream fp;
  fp.open(filename,ios::in);
  if(!fp.is_open()){
    return 1;
  }
  fp.seekg (0, fp.end);
    int length = fp.tellg();
    fp.seekg (0, fp.beg);
    if (length == 0) {
    cols = 0;
    rows = 0;
    pixels = NULL;
    fp.close();
      return 0;
  }
  int pix,total_num=0,cline=0,ccol;
  char line[1500];
  while (!fp.eof()){
    fp >> pix;
    total_num++;
  }
  total_num = total_num -1; 
  fp.clear();
  fp.seekg (0, fp.beg);
  while (!fp.eof()){
    fp.getline(line,1500,'\n');
    cline ++;
  }
  cline = cline - 1;  
  fp.clear();
  fp.seekg (0, fp.beg);
  if (cline == 0){
    ccol = 0;
    cols = ccol;
    rows = 0;
    if (pixels != NULL){
      for (int i = 0; i < rows; i++) {
          delete[] pixels[i];
      }
      delete [] pixels;
      pixels = NULL;  
    }
    fp.close();
    return 0;
  }
  else{
    ccol = total_num/cline;
    cols = ccol;
    rows = cline; 
  }
  if (pixels != NULL){
      for (int i = 0; i < rows; i++) {
          delete[] pixels[i];
      }
      delete [] pixels;
  }   
  pixels = new uint8_t*[rows];
  for(int i = 0; i < rows; ++i){
      pixels[i] = new uint8_t[cols];
  }     
  for (int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      fp >> pix;
      pixels[i][j] = pix;
    }
  }
  fp.close();
  return 0;
 }