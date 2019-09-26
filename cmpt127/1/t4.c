#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float i = 0;

  int res = scanf( "%f", &i );
  if( res == 1 ){
  printf("%.0f %.0f %.0f\n",floor(i),round(i),ceil(i));
}else{
  printf("scanf error: (%d)\n", res);
}
  return 0;
}
