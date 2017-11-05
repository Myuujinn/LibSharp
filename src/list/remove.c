/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Remove function of the LibSharp's lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include "libsharp.h"

static void	strlist_remove(strlist_t *list, uint index)
{
	if (list->size >= index)
		free(list->list[index]);
	for (uint i = index; list->size >= i; i++)
		if (i + 1 < list->size)
			list->list[i] = list->list[i + 1];
	list->size--;
}

static void	longlist_remove(longlist_t *list, uint index)
{
	if (list->list == NULL || list->size == 0)
		libsharp_error("longlist_remove: list data is null.");
	for (uint i = index; list->size >= i; i++)
		if (i + 1 < list->size)
			list->list[i] = list->list[i + 1];
	list->size--;
}

static void	ptrlist_remove(ptrlist_t *list, uint index)
{
	if (list->list == NULL || list->size == 0)
		libsharp_error("ptrlist_remove: list data is null.");
	for (uint i = index; list->size >= i; i++)
		if (i + 1 < list->size)
			list->list[i] = list->list[i + 1];
	list->size--;
}

void	list_remove(list_t *list, uint index)
{
	if (list != NULL)
		switch (list->type) {
		case (STRING_LIST) :
			strlist_remove(list->data, index);
			break ;
		case (POINTER_LIST) :
			ptrlist_remove(list->data, index);
			break ;
		case (LONG_LIST) :
			longlist_remove(list->data, index);
			break ;
		}
	else
		libsharp_error("list_remove: list is null.");
}
