#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"

void main(int argc, char const *argv[])
{
	list_t* list1 = list_create();
	list_append(list1, 1);
	list_append(list1, 3);
	list_append(list1, 8);
	list_append(list1, 2);
	list_prepend(list1,3);
	list_print(list1);
	list_sort(list1);
	list_print(list1);
	list_destroy(list1);
	list_print(list1);
}