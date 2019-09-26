#include <stdio.h>

int main(void){
  int i = 0;
  int a = scanf("%u", &i);
  while(a!=EOF){
     for(int times = 1; times<=i; times++){
	printf("#");}
     printf("\n");
     a = scanf("%u", &i);
  }
return 0;
}
