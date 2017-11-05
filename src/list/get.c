/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Get function for the LibSharp's lists.
*/

#include <stdio.h>
#include "libsharp.h"

static void	*get_data_from_type(list_t *list, uint index)
{
	switch (list->type) {
	case (STRING_LIST) :
		return (((strlist_t *)list->data)->list[index]);
	case (POINTER_LIST) :
		return (((ptrlist_t *)list->data)->list[index]);
	case (LONG_LIST) :
		return ((void *)((longlist_t *)list->data)->list[index]);
	}
	return (NULL);
}

static void	*choose_which_type(list_t *list, uint index)
{
	if (index < *list->size)
		get_data_from_type(list, index);
	else
		libsharp_error("list_get: out of bounds.");
	return (NULL);
}

void	*list_get(list_t *list, uint index)
{
	if (list != NULL) {
		return (choose_which_type(list, index));
	}
	libsharp_error("list_get: list is null.");
	return (NULL);
}
