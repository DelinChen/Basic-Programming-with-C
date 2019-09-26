#include <stdio.h>
#include <math.h>
 
int main( void )
{
  double i = 0;

  scanf( "%lf", &i );
  printf("%d %d %d\n",(int)floor(i),(int)round(i),(int)ceil(i));
 
  return 0;
}
