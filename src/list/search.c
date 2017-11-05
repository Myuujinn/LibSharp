/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Search function for the LibSharp's lists.
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

static uint	strlist_search(strlist_t *list, char *string)
{
	if (string != NULL) {
		for (uint i = 0; list->size > i; i++)
			if (strcmp(list->list[i], string) == 0)
				return (i);
	} else
		fprintf(stderr, "[LibSharp] strlist_search: string is null.\n");
	return ((uint)-1);
}

static uint	ptrlist_search(ptrlist_t *list, void *ptr)
{
	if (ptr != NULL) {
		for (uint i = 0; list->size > i; i++)
			if (list->list[i] == ptr)
				return (i);
	} else
		fprintf(stderr, "[LibSharp] ptrlist_search: pointer is null.\n");
	return ((uint)-1);
}

static uint	longlist_search(longlist_t *list, long longint)
{
        for (uint i = 0; list->size > i; i++)
		if (list->list[i] == longint)
			return (i);
	return ((uint)-1);
}

uint	list_search(list_t *list, void *data)
{
	if (list != NULL) {
		switch (list->type) {
		case (STRING_LIST) :
			return (strlist_search(list->data, data));
		case (POINTER_LIST) :
			return (ptrlist_search(list->data, data));
		case (LONG_LIST) :
			return (longlist_search(list->data, (long)data));
		}
	} else
		fprintf(stderr, "[LibSharp] list_search: list is null.\n");
	return ((uint)-1);
}
