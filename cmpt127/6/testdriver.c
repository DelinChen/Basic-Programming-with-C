#include <stdio.h>
#include "intarr.h"

int main()
{
    intarr_t* new= intarr_create(5);
    intarr_set(new,0,5);
    intarr_set(new,1,6);
    intarr_set(new,2,4);
    intarr_set(new,3,8);
    intarr_set(new,4,3);
    int val[5]={2,3,4,5,6};
    new->len=5;
    new->data=val;
    printf("%d\n",new->data[3]);
    //new->data=values;
    //char filename[11]="myfiel.txt";
    //intarr_save_binary( array, filename );
    //intarr_t *gett=intarr_load_binary( filename );
    //printf("%d",gett->len);
    return 0;

}
