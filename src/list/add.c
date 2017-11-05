/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Add function of the LibSharp's lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

static void	strlist_add(strlist_t *list, char *string)
{
	char	**newlist;

	newlist = malloc(sizeof(char *) * (list->size + 1));
	if (newlist == NULL)
		malloc_exit("[LibSharp] strlist_add");
	memcpy(newlist, list->list, sizeof(char *) * list->size);
	newlist[list->size++] = strdup(string);
	if (list->list != NULL)
		free(list->list);
	list->list = newlist;
}

static void	longlist_add(longlist_t *list, long longint)
{
	long	*newlist;

	newlist = malloc(sizeof(long) * (list->size + 1));
	if (newlist == NULL)
		malloc_exit("[LibSharp longlist_add");
	memcpy(newlist, list->list, sizeof(long) * list->size);
	newlist[list->size++] = longint;
	if (list->list != NULL)
		free(list->list);
	list->list = newlist;
}

static void	ptrlist_add(ptrlist_t *list, void *ptr)
{
	void	**newlist;

	newlist = malloc(sizeof(void *) * (list->size + 1));
	if (newlist == NULL)
		malloc_exit("[LibSharp longlist_add");
	memcpy(newlist, list->list, sizeof(void *) * list->size);
	newlist[list->size++] = ptr;
	if (list->list != NULL)
		free(list->list);
	list->list = newlist;
}

void	list_add(list_t *list, void *data)
{
	if (list != NULL && data != NULL) {
		switch (list->type) {
		case (STRING_LIST) :
			strlist_add(list->data, (char *)data);
			break ;
		case (POINTER_LIST) :
		        ptrlist_add(list->data, data);
			break ;
		case (LONG_LIST) :
			longlist_add(list->data, (long)data);
			break ;
		}
	} else
		fprintf(stderr, "[LibSharp] list_add: null arguments.\n");
}
