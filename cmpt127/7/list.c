#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

list_t * list_create() {
    list_t * ret = malloc(sizeof(list_t));
    if (ret != NULL) {
        ret->head = NULL;
        ret->tail = NULL;
    }
    return ret;
}

void list_destroy( list_t* list ){
	element_t* curr = list->head;
	element_t* next;
	while (curr!=NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
	list->tail = NULL;
}


element_t* element_create( int i ){
	if(i){
		element_t* newNode = malloc(sizeof(element_t));
		newNode->val = i;
		newNode->next = NULL;
	}
}


int list_append( list_t* list, int i ){
	element_t* newNode = malloc(sizeof(element_t));
	if (newNode == NULL)
	{
		return 1;
	}
	newNode->val = i;
	newNode->next = NULL;
	if(list->head==NULL){
		list->head = newNode;
	}
	if (list->tail)
	{
		list->tail->next = newNode;
	}
	list->tail = newNode;
	return 0;
}


int list_prepend( list_t* list, int i ){
	element_t* newNode = malloc(sizeof(element_t));
	if (newNode == NULL)
	{
		return 1;
	}
	newNode->val = i;
	newNode->next = NULL;
	if (list->tail==NULL)
	{
		list->tail = newNode;
	}
	if (list->head)
	{
		newNode->next = list->head;
	}
	list->head = newNode;
	return 0;
}


element_t* list_index( list_t* list, unsigned int i ){
	element_t* curr = list->head;
	int k=0;
	if (list->head == NULL)
	{
		return NULL;
	}
	while(curr != NULL)
	{
		if (k==i)
		{
			return curr;
		}		
		k++;
		curr = curr->next;
	}
	return NULL;
}


void list_print( list_t* list ){
    element_t * current = list->head;
    while (current != NULL) {
        printf(" %d", current->val);
        current = current->next;
    }
    putchar('\n');
}
