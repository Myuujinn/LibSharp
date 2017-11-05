/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Header file for all list related stuff
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>

#define LIST	list_t	*

typedef enum	list_types_e
{
	STRING_LIST,
	POINTER_LIST,
	LONG_LIST
}		list_types_t;

typedef struct	list_s
{
	char	type;
	uint	*size;
	void	*data;
}		list_t;

typedef struct	strlist_s
{
	uint	size;
	char	**list;
}		strlist_t;

typedef struct	longlist_s
{
	uint	size;
	long	*list;
}		longlist_t;

typedef struct	ptrlist_s
{
	uint	size;
	void	**list;
}		ptrlist_t;

list_t		*list_create(list_types_t data_type);
void		list_add(list_t *list, void *data);
void		list_print(list_t *list);
void		list_destroy(list_t *list);
void		list_remove(list_t *list, uint index);
void		list_import(list_t *list, void *data, uint size);
void		*list_get(list_t *list, uint index);
uint		list_search(list_t *list, void *data);

void		list_swap(list_t *list, uint index, uint index2);
void		strlist_swap(strlist_t *list, uint index, uint index2);
void		longlist_swap(longlist_t *list, uint index, uint index2);
void		list_sort(list_t *list);
