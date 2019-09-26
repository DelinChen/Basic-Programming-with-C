#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"



int main( int argc, char* argv[] )
{
	  // testing element create function
  element_t* el = malloc(sizeof(element_t));
  assert(el);
  memset(el,0xFF,sizeof(element_t));
  free(el);

  el = element_create(1492);
  assert(el);

  // check to see if the create function did everything it was supposed to
  if( el->val != 1492 )
    {
      printf( "element_create():element->val not correct\n" );
      return 1;
    }
  if (el->next){
    puts("error!");
    return 1;
  }

  //testing list create function
  list_t* list = list_create();


  element_t* node1 = list_index(list,1);
  if (node1 != NULL)//
  {
  	puts("indexing error!");
  	return 1;
  }



  // testing prepend function
  int val = 26;
  list_prepend( list, val);
  if (list->head == NULL){
    puts("list_prepend():list->head NULL");
    return 1;
  }
  if (list->tail == NULL){
    puts("list_prepend():list->tail NULL");
    return 1;
  }  
  if (list->head != list->tail){
    puts("list_prepend():head != tail");
    return 1;
  }
  if (list->head->next != NULL){
    puts("list_prepend():list->head->next not NULL");
    return 1;
  }
  if (list->head->val != val){
    puts("list_prepend():list->head->val not correct");
  }


  //testing append function
  list_append( list, 15);
  list_print(list);
  if (list->head == NULL){
    puts("list_append():list->head NULL");
    return 1;
  }
  if (list->tail == NULL){
    puts("list_append():list->tail NULL");
    return 1;
  }  

  if (list->tail->val != 15){
    puts("list_append():list->tail->val not correct");
    return 1;
  }


  element_t* n1 = list_index(list,0);
  element_t* n2 = list_index(list,5);
  if (n1->val !=26)
  {
    puts("indexing not correct!");
  	return 1;
  }
  if (n2!=NULL)
  {
    puts("index out of range!");
  	return 1;
  }

  //destroy 
  list_destroy(list);

  return 0;

}
