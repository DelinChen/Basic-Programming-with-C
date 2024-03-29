#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void list_catenate(list_t * L1, list_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}


void list_sort( list_t* list )

{

    if (list->head == list->tail) {
        return;
    }    
    int pivot = list->head->val;
    
    element_t * pivot_element = list->head;
    
    list->head = list->head->next;

    list_t * first = list_create();
    
    list_t * second = list_create();
    
    element_t * curr = list->head;
    
    element_t * next;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            list_append( first, curr->val );            
            
        } else {            
            list_append( second, curr->val );
        }
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list_sort(first);
    list_sort(second);
    list_catenate(list, first);
    list_append( list, pivot_element->val);
    
    list_catenate(list, second);
}