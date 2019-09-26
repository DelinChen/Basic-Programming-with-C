#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if (strstr(argv[1],argv[2])){
		printf("true\n");
	}else
printf("false\n");
	return 0;
}