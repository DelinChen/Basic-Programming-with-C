#include <stdio.h>
#include <string.h>
#include <ctype.h>
     
int main(void){
  int counter = 0, count[26]={0}, x, n;
  while ((n = getchar())!= EOF){
    if (isalpha(n) != 0){
      n = tolower(n);
      counter++;
      x = n-'a';
      count[x]++;
    }
  }
  for (int i = 0; i < 26; ++i){
    if(count[i]/(float)counter!=0){
      printf("%c %.4f\n",i+'a', count[i]/(float)counter);
  }
}
}