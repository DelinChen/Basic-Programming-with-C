#include <stdio.h>
 
int main( void ){
  float num = 0, max = 0, min = 0, sum = 0;
  int count = 0;

  int res = scanf("%f", &num);
  max = num;
  min = num;

  while ( res != EOF ){
    sum += num;
    count += 1;

    if ( num > max ){
       max = num; 
    }
    if ( num < min ){
       min = num; 
    }
    
    res = scanf("%f", &num);
    }

  printf("%.2f %.2f %.2f\n",min,max,sum/(float)count);
  return 0;
}