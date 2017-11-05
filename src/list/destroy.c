/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Destroy function for the LibSharp's lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void	strlist_destroy(strlist_t *list)
{
	if (list->list != NULL)	{
		for (uint i = 0; i < list->size; i++)
			if (list->list[i] != NULL)
				free(list->list[i - 1]);
		free(list->list);
	}
	free(list);
}

static void	longlist_destroy(longlist_t *list)
{
	if (list->list != NULL)
		free(list->list);
	free(list);
}

static void	ptrlist_destroy(ptrlist_t *list)
{
	if (list->list != NULL)
		free(list->list);
	free(list);
}

void	list_destroy(list_t *list)
{
	if (list != NULL && list->data != NULL)	{
		switch (list->type) {
		case (STRING_LIST) :
			strlist_destroy(list->data);
			break ;
		case (POINTER_LIST) :
			ptrlist_destroy(list->data);
			break ;
		case (LONG_LIST) :
			longlist_destroy(list->data);
			break ;
		}
		free(list);
	} else
		fprintf(stderr, "[LibSharp] list_destroy: list is null.\n");
}
