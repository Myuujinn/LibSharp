/*
** list.h for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Aug 21 20:03:35 2017 Victor LE DANTEC
** Last update Tue Aug 29 20:14:21 2017 Victor LE DANTEC
*/

#pragma once

#include <stddef.h>

#define LIST	t_list*

typedef enum	e_list_types
  {
    STRING_LIST,
    POINTER_LIST,
    LONG_LIST
  }		t_list_types;

typedef struct	s_list
{
  char		type;
  size_t	*size;
  void		*data;
}		t_list;

typedef struct	s_strlist
{
  size_t	size;
  char		**list;
}		t_strlist;

typedef struct	s_longlist
{
  size_t	size;
  long		*list;
}		t_longlist;

typedef struct	s_ptrlist
{
  size_t	size;
  void		**list;
}		t_ptrlist;

t_list		*list_create(t_list_types data_type);
void		list_add(t_list *list, void *data);
void		list_print(t_list *list);
void		list_destroy(t_list *list);
void		list_remove(t_list *list, size_t index);
void		list_import(t_list *list, void *data, size_t size);
void		*list_get(t_list *list, size_t index);

void		list_swap(t_list *list, size_t index, size_t index2);
void		strlist_swap(t_strlist *list, size_t index, size_t index2);
void		longlist_swap(t_longlist *list, size_t index, size_t index2);
void		list_sort(t_list *list);
