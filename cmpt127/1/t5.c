#include <stdio.h>
#include <math.h>

int main( void )
{
  float i = 0;
  int res = scanf( "%f", &i );
  while( res == 1 ){
  printf("%.0f %.0f %.0f\n",floor(i),round(i),ceil(i));
  res = scanf( "%f", &i );
  if( res == EOF ) {
  printf("Done.\n");
  }}
  return 0;
}
