/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Import function of the LibSharp's lists.
*/

#include <stdio.h>
#include "libsharp.h"

static void	strlist_import(list_t *list, void *data, uint size)
{
        if (data != NULL)
		for (uint i = 0; ((char **)data)[i] != NULL && i < size; i++)
			list_add(list, ((char **)data)[i]);
}

static void	longlist_import(list_t *list, void *data, uint size)
{
	if (data != NULL)
		for (uint i = 0; i < size; i++)
			list_add(list, (void *)((long *)data)[i]);
}

static void	ptrlist_import(list_t *list, void *data, uint size)
{
	if (data != NULL)
		for (uint i = 0; i < size; i++)
			list_add(list, ((void **)data)[i]);
}

void	list_import(list_t *list, void *data, uint size)
{
	if (list != NULL) {
		switch (list->type) {
		case (STRING_LIST) :
			strlist_import(list, data, size);
			break ;
		case (POINTER_LIST) :
			ptrlist_import(list, data, size);
			break ;
		case (LONG_LIST) :
			longlist_import(list, data, size);
			break ;
		}
	} else
		libsharp_error("list_import: list is null.");
}
