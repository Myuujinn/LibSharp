/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Sort function for the LibSharp's lists.
*/

#include <stdio.h>
#include <string.h>
#include "libsharp.h"

static void	strlist_insertion_sort(strlist_t *list, uint i)
{
	for (; i > 0 && strcasecmp(list->list[i], list->list[i - 1]) < 0; i--)
		strlist_swap(list, i, i - 1);
}

static void	strlist_sort(strlist_t *list)
{
	if (list->size != 0)
		for (uint i = 1; i < list->size; i++)
        		strlist_insertion_sort(list, i);
}

static void	longlist_insertion_sort(longlist_t *list, uint i)
{
	for (; i > 0 && list->list[i] < list->list[i - 1]; i--)
		longlist_swap(list, i, i - 1);
}

static void	longlist_sort(longlist_t *list)
{
        if (list->size != 0)
		for (uint i = 1; i < list->size; i++)
			longlist_insertion_sort(list, i);
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
		libsharp_error("list_sort: list is null.");
}
