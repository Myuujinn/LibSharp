/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Swap function for the LibSharp's lists.
*/

#include <stdio.h>
#include "list.h"

void	strlist_swap(strlist_t *list, uint index, uint index2)
{
	char	*save;

	if (index >= list->size || index2 >= list->size)
		fprintf(stderr, "[LibSharp] strlist_swap: out of bounds.\n");
	else if (index == index2)
		fprintf(stderr, "[LibSharp] strlist_swap: same index.\n");
	else {
		save = list->list[index];
		list->list[index] = list->list[index2];
		list->list[index2] = save;
	}
}

void	longlist_swap(longlist_t *list, uint index, uint index2)
{
	long	save;

	if (index >= list->size || index2 >= list->size)
		fprintf(stderr, "[LibSharp] longlist_swap: out of bounds.\n");
	else if (index == index2)
		fprintf(stderr, "[LibSharp] longlist_swap: same index.\n");
	else {
		save = list->list[index];
		list->list[index] = list->list[index2];
		list->list[index2] = save;
	}
}

void	ptrlist_swap(ptrlist_t *list, uint index, uint index2)
{
	void	*save;

	if (index >= list->size || index2 >= list->size)
		fprintf(stderr, "[LibSharp] ptrlist_swap: out of bounds.\n");
	else if (index == index2)
		fprintf(stderr, "[LibSharp] ptrlist_swap: same index.\n");
	else {
		save = list->list[index];
		list->list[index] = list->list[index2];
		list->list[index2] = save;
	}
}

void	list_swap(list_t *list, uint index, uint index2)
{
	if (list != NULL)
		switch (list->type) {
		case (STRING_LIST) :
			strlist_swap(list->data, index, index2);
			break ;
		case (POINTER_LIST) :
			ptrlist_swap(list->data, index, index2);
			break ;
		case (LONG_LIST) :
			longlist_swap(list->data, index, index2);
			break ;
		}
	else
		fprintf(stderr, "[LibSharp] list_swap: list is null.\n");
}
