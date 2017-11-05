/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Print function of the LibSharp's lists.
*/

#include <stdio.h>
#include "list.h"

static void	strlist_print(strlist_t *list)
{
	printf("{ ");
	for (uint i = 0; i < list->size; i++) {
		printf("\"%s\"", (list->list[i]));
		if (i + 1 < list->size)
			printf(", ");
	}
	printf(" }\n");
}

static void	longlist_print(longlist_t *list)
{
	printf("{ ");
	for (uint i = 0; i < list->size; i++) {
		printf("%ld", (list->list[i]));
		if (i + 1 < list->size)
			printf(", ");
	}
	printf(" }\n");
}

static void	ptrlist_print(ptrlist_t *list)
{
	printf("{ ");
	for (uint i = 0; i < list->size; i++) {
		printf("%p", (list->list[i]));
		if (i + 1 < list->size)
			printf(", ");
	}
	printf(" }\n");
}

void	list_print(list_t *list)
{
	switch (list->type) {
	case (STRING_LIST) :
		strlist_print(list->data);
		break ;
	case (POINTER_LIST) :
		ptrlist_print(list->data);
		break ;
	case (LONG_LIST) :
		longlist_print(list->data);
		break ;
	}
}
