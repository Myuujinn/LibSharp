/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Sort function for the LibSharp's lists.
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

static void	strlist_sort(strlist_t *list)
{
	uint	i = 1;

	if (list->size != 0)
		while (i < list->size)
        		for (uint j = i++; j > 0 && strcasecmp(list->list[j], list->list[j - 1]) < 0; j--)
				strlist_swap(list, j, j - 1);
}

static void	longlist_sort(longlist_t *list)
{
	uint	i = 1;
	
	if (list->size != 0)
		while (i < list->size)
			for (uint j = i++; j > 0 && list->list[j] < list->list[j - 1]; j--)
				longlist_swap(list, j, j - 1);
}

void	list_sort(list_t *list)
{
	if (list != NULL)
		switch (list->type) {
		case (STRING_LIST) :
			strlist_sort(list->data);
			break ;
		case (LONG_LIST) :
			longlist_sort(list->data);
			break ;
		}
	else
		fprintf(stderr, "[LibSharp] list_sort: list is null.\n");
}
