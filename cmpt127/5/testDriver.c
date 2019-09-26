#include <stdio.h>
#include "intarr.h"

int main()
{
	
    printf("TASK 1\n");
    intarr_t* new = intarr_create(5);
    printf("%d\n",new->len);
    //task 2
    printf("TASK 2\n");
    intarr_set(new,0,9);
    printf("%d\n",new->data[0]);
    //    bool cond = (new->data[1]==NULL);
    //printf("%d\n",new->data[0]==0);
    int i = 2;
    printf("%d\n",i);
    intarr_get(new,1,&i);
    printf("%d\n",i);

    //task 3
    // new = 96483
    intarr_set(new,1,6);
    intarr_set(new,2,4);
    intarr_set(new,3,8);
    intarr_set(new,4,3);
    intarr_t* new_copy= intarr_copy( new );
    printf("TASK 3 \n");
    printf("Length is %d\n",new_copy->len);
    int iter;
    for(iter=0; iter<5; iter++){
        printf("%d ",new_copy->data[iter]);
    }
    printf("\n");

    //task 4
    // new = 96483
    // after sort, 34689
    printf("TASK 4\n");
    //intarr_set(new,1,6);
    //intarr_set(new,2,4);
    //intarr_set(new,3,8);
    //intarr_set(new,4,3);
    
    for(iter=0; iter<5; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\n");
    intarr_sort( new );
    for(iter=0; iter<5; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\n");

    //task 5
    //new = 34689
    //after found 34689
    //new w = 4 (location index
    int w;
    printf("TASK 5\n");
    intarr_find( new, 9, &w );
    for(iter=0; iter<5; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\nlocation index i:%d\n", w);

    // task 6a
    // NEW = 34689
    // ADD 1
    // 346891
    printf("TASK 6a\n");
    intarr_push( new, 9 );
    intarr_push( new, 7 );

    for(iter=0; iter<new->len; iter++){
        printf("%d ",new->data[iter]);
    }



    // task 6b
    // new = 3468997
    // pop 7
    // return 346899
    intarr_set(new,3,0);
    // new 346099
    printf("\nTASK 6b\nNew array:");
    int t6b = -1;
    intarr_pop( new, &t6b );
    for(iter=0; iter<new->len; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\nWhat removed is %d\n",t6b);
    printf("New array:");
    intarr_pop( new, &t6b );
    for(iter=0; iter<new->len; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\nWhat removed is %d\n",t6b);
    
    //task 7
    // new = 34609 size=5
    // after resize (newlen=8)  new=34609000
    // after resize (newlen=4)  new=3460
    // after resize (newlen=6)  new=346000

    printf("TASK 7\n");
    intarr_resize( new, 15 );
    printf("New array:");
    for(iter=0; iter<new->len; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\nNew array:");
    intarr_resize( new, 10);
    for(iter=0; iter<new->len; iter++){
        printf("%d ",new->data[iter]);
    }
    printf("\n");

    //task 8
    //new = 34609
    //first 1 ; last 3 ; subarray_copy = 468
    //
    printf("TASK 8\n");
    intarr_t *subarray_copy=intarr_copy_subarray( new , 1 , 4);
    int m;
    for (m=0;m<subarray_copy->len;m++)
    {
        printf("%d ",subarray_copy->data[m]);
    }
    printf("\n");


	return 0;
}