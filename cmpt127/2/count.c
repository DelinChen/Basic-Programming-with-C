#include <stdio.h>
#include <ctype.h>

int main (void){
	long int charcount = 0, wordcount = 0, linecount = 0;
	char n;
	int word = 1;
	while ((n = getchar())!= EOF){
		charcount++;
		if (n == '\n'){
			linecount++;
			word = 1;
		}
		else if (n == '\'' ||(n>='a' && n<='z')||(n>='A' && n<='Z')){
			if(word == 1){
				wordcount++;
				word = 0;
			}}
			else{
				word = 1;
			}
	}
	printf( "%lu %lu %lu\n", charcount, wordcount, linecount);
	return 0;
}
