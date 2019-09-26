#include <stdio.h>

int main(){
	int a, b, c, d, i, j, k;
	d = scanf("%d %d %d", &a, &b, &c);
	for (i = 1; i <= a; i++){
		printf("#");
	}
	printf("\n");
	for (j = 3; j <= b; j++){
		printf("#");
		for (k = 3; k <= a; k++){
			printf(".");
		}
		printf("#\n");
	}
	if (b > 1){
	for (i = 1; i <= a; i++){
		printf("#");
	}
	printf("\n");
	}
	return 0;
}