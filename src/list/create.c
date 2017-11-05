/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Create function for the LibSharp's lists.
*/

#include <stdlib.h>
#include "libsharp.h"
#include "list.h"

static strlist_t	*stringlist_create()
{
	strlist_t	*list;

	list = malloc(sizeof(strlist_t));
	if (list == NULL)
		malloc_exit("[LibSharp] stringlist_create");
	list->size = 0;
	list->list = NULL;
	return (list);
}

static longlist_t	*longlist_create()
{
	longlist_t	*list;

	list = malloc(sizeof(longlist_t));
	if (list == NULL)
		malloc_exit("[LibSharp] stringlist_create");
	list->size = 0;
	list->list = NULL;
	return (list);
}

static ptrlist_t	*ptrlist_create()
{
	ptrlist_t	*list;

	list = malloc(sizeof(ptrlist_t));
	if (list == NULL)
		malloc_exit("[LibSharp] stringlist_create");
	list->size = 0;
	list->list = NULL;
	return (list);
}

static void	allocate_list(list_t *list)
{
	switch (list->type) {
	case (STRING_LIST) :
		list->data = stringlist_create();
		break ;
	case (POINTER_LIST) :
		list->data = ptrlist_create();
		break ;
	case (LONG_LIST) :
		list->data = longlist_create();
		break ;
	}
}

list_t		*list_create(list_types_t data_type)
{
	list_t	*list;

	list = malloc(sizeof(list_t));
	if (list == NULL)
		return (NULL);
	if (data_type > LONG_LIST)
		error_exit("[LibSharp] list_create", "data type unknown.");
	list->type = data_type;
	allocate_list(list);
	list->size = &(((strlist_t *)list->data)->size);
	return (list);
}
