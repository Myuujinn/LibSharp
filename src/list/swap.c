/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Swap function for the LibSharp's lists.
*/

#include <stdio.h>
#include "libsharp.h"

void	strlist_swap(strlist_t *list, uint index, uint index2)
{
	char	*save;

	if (index >= list->size || index2 >= list->size)
		libsharp_error("strlist_swap: out of bounds.");
	else if (index == index2)
		libsharp_error("strlist_swap: same index.");
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
		libsharp_error("longlist_swap: out of bounds.");
	else if (index == index2)
		libsharp_error("[LibSharp] longlist_swap: same index.");
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
		libsharp_error("ptrlist_swap: out of bounds.");
	else if (index == index2)
		libsharp_error("ptrlist_swap: same index.");
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
		libsharp_error("list_swap: list is null.");
}
