#include <stdio.h>

int main(void)
{
	int arr[80],count=0, input, max = 0;
	while (input != EOF){
		input = scanf("%d", &arr[count]);
		count++;
	}

	for (int i=0;i<count-1;i++){
		if (arr[i]>max){
			max = arr [i];
		}
	}
	for (int k=max; k>0; k--){
		for(int j=0;j<count-1;j++){
			if(arr[j] >= k){
				printf("#");
			}
			else{
			printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
