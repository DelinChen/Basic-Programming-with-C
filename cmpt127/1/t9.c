#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c, d, i, j;
	d = scanf("%d %d %d", &a, &b, &c);
	for (i=c-1; i>=0; i--){
		int e = floor(i*(a/(2.0*c)));
		int f = ceil((a-1)-i*(a/(2.0*c)));
		if (i == 0){
			for	(j=0; j<a; j++){
				printf("#");}
		printf("\n");
		}
		else if (i==c-1){
			for(j=0;j<=a;j++){
				if(j>=e&&j<=f){
					printf("#");
				}
				else if(j<e){
					printf(" ");
				    }
				}
			printf("\n");
		}
		else{
			for (j=0;j<=f;j++){
				if(j<e){
					printf(" ");}
				else if(j==e||j==f){
					printf("#");
				}
				else{
					printf(".");}
			}
			printf("\n");
		}
	}
	return 0;
}