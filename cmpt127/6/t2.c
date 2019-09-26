#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int intarr_save_json( intarr_t* ia, const char* filename )
{
    if ( ia==NULL || ia->data==NULL ||filename==NULL){
        return 1;
    }

    FILE *new=fopen(filename,"w+");
    fprintf(new,"[");
    for (int i=0;i<ia->len;i++){
        fprintf(new," %d",ia->data[i]);
        if (i!=ia->len-1){
            fprintf(new,",");
        }
    }
    fprintf(new," ]");
    fclose(new);
    return 0;
}

intarr_t* intarr_load_json( const char* filename ){

    if(filename==NULL){
        return NULL;
    }
    FILE * file = fopen(filename, "r");

    if(file==NULL){
        return NULL;
    }
    fscanf(file,"[ ");

    intarr_t* new = intarr_create(0);

    int tmp;
    while( fscanf(file,"%d,",&tmp)==1){
        intarr_push(new, tmp);
    }
    fclose(file);
    return new;

    /*
    if (filename == NULL){
        return NULL;
    }
    FILE * file = fopen (filename, "r");

    int count=0;
    char ch;
    int k,i=0;
    intarr_t *new = malloc(sizeof(intarr_t));
    
    
    while (!feof(file)){    // count number of elements  
        ch = getc(file);
        if (ch == ','){
            count ++;
        }
    }

    fseek(file,0,SEEK_SET);
    if (count==0&& ch == NULL)
    {
        new->len = 0;
        new->data = NULL;
        return new;
    }


    new->len=count+1;
    new->data=malloc(sizeof(int)*new->len);
       
    while(i<new->len){
        while (fscanf(file, "%d",&k)!=1){
            fseek(file, 1, SEEK_CUR);      
        }
        new->data[i]=k;
        i++;
        }
    fseek(file,0,SEEK_END);
    fclose(file);

    
    return new;
    */
}