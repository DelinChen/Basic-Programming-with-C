#include "point_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*
typedef struct point
{
  double x, y, z;
} point_t;

typedef struct 
{
  // number of points in the array
  size_t len;
  
  // pointer to an array of point_t structs
  // There is space for 'allocated' structs, but 
  // 'len' structs have been used so far.
  point_t* points;
  
  // to be discussed in class - see Demo
  size_t reserved; 
  
} point_array_t;
*/

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
  pa->len = 0;
  pa->reserved = 0;
  pa->points = malloc(sizeof(point_t));
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa ){
  for (int k = 0;k < pa->len;k ++){
    pa->points[k].x = 0;
    pa->points[k].y = 0;
    pa->points[k].z = 0;
  pa->len = 0;
  pa->points = realloc(pa->points,0);
}
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p ){
  if (p==NULL)
  {
    return 0;
  }
  pa->len++;
  pa->points = realloc(pa->points,sizeof(point_t)*pa->len);
  if (pa->points == NULL){
    return 1;
  }
  pa->points[pa->len-1].x = p->x;
  pa->points[pa->len-1].y = p->y;
  pa->points[pa->len-1].z = p->z;
  return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i ){
  if (i>=pa->len)
  {
    return 1;
  }
  pa->points[i].x = 0;
  pa->points[i].y = 0;
  pa->points[i].z = 0;
  pa->len--;
  pa->points = realloc(pa->points,sizeof(point_t)*pa->len);
  return 0;
}