/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Get function for the LibSharp's lists.
*/

#include <stdio.h>
#include "list.h"

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
		fprintf(stderr, "[LibSharp] list_get: out of bounds.\n");
	return (NULL);
}

void	*list_get(list_t *list, uint index)
{
	if (list != NULL) {
		return (choose_which_type(list, index)); 
	}
	fprintf(stderr, "[LibSharp] list_get: list is null.\n");
	return (NULL);
}
