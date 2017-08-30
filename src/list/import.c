/*
** import.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 20:28:45 2017 Victor LE DANTEC
** Last update Wed Aug 30 19:15:17 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "list.h"

static void	strlist_import(t_list *list, void *data, size_t size)
{
  size_t	i;

  i = 0;
  if (data != NULL)
    while (((char **)data)[i] != NULL && i < size)
      list_add(list, ((char **)data)[i++]);
}

static void	longlist_import(t_list *list, void *data, size_t size)
{
  size_t	i;

  i = 0;
  if (data != NULL)
    while (i < size)
      list_add(list, (void *)((long *)data)[i++]);
}

static void	ptrlist_import(t_list *list, void *data, size_t size)
{
  size_t	i;

  i = 0;
  if (data != NULL)
    while (i < size)
      list_add(list, ((void **)data)[i++]);
}

void	list_import(t_list *list, void *data, size_t size)
{
  if (list != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_import(list, data, size);
      else if (list->type == POINTER_LIST)
	ptrlist_import(list, data, size);
      else if (list->type == LONG_LIST)
	longlist_import(list, data, size);
    }
  else
    fprintf(stderr, "[LibSharp] list_import: list is null.\n");
}
