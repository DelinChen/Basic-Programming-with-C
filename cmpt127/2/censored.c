#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
 {
 	char *result;
 	int length,len;
 	int i=0,j;
	char c[10000];
	while(fgets(c,100,stdin) != NULL)		
{			
		
		if (argc==2)
		{
			if ((result=strstr(c, argv[1]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[1]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
				
			}
			else
			{
				
				printf("%s", c);
			}
		}
		else if (argc==3)
		{
			if ((result=strstr(c, argv[1]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[1]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
				
			}
			else if ((result=strstr(c, argv[2]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[2]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
			}
			else
			{
				
				printf("%s", c);
			}
		}
		else if (argc==4)
		{
			if ((result=strstr(c, argv[1]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[1]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
				
			}
			else if ((result=strstr(c, argv[2]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[2]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
				
			}
			else if ((result=strstr(c, argv[3]))!= NULL)
			{	
				len=strlen(result);
				length=strlen(c);
				for (i=0;i<length-len;i++)
				{
					printf("%c",c[i]);
				}
				printf("CENSORED");
				for (j=length-len+strlen(argv[3]);j<length;j++)
	            {
	            	printf("%c",c[j]);
	            }
				
			}
			else
			{
				
				printf("%s", c);
			}
			
		}	
		
	}
	return 0;
}