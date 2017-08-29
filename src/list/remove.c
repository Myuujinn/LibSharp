/*
** remove.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 17:58:21 2017 Victor LE DANTEC
** Last update Tue Aug 29 19:14:18 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void	strlist_remove(t_strlist *list, size_t index)
{
  size_t	i;

  i = index;
  if (list->size >= index)
    free(list->list[i]);
  while (list->size >= i)
    {
      if (i + 1 < list->size)
	list->list[i] = list->list[i + 1];
      i++;
    }
  list->size--;
}

static void	longlist_remove(t_longlist *list, size_t index)
{
  size_t	i;

  if (list->list == NULL || list->size == 0)
    fprintf(stderr, "[LibSharp] longlist_remove: list data is null.\n");
  i = index;
  while (list->size >= i)
    {
      if (i + 1 < list->size)
	list->list[i] = list->list[i + 1];
      i++;
    }
  list->size--;
}

static void	ptrlist_remove(t_ptrlist *list, size_t index)
{
  size_t	i;

  if (list->list == NULL || list->size == 0)
    fprintf(stderr, "[LibSharp] ptrlist_remove: list data is null.\n");
  i = index;
  while (list->size >= i)
    {
      if (i + 1 < list->size)
	list->list[i] = list->list[i + 1];
      i++;
    }
  list->size--;
}

void	list_remove(t_list *list, size_t index)
{
  if (list != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_remove(list->data, index);
      else if (list->type == POINTER_LIST)
	ptrlist_remove(list->data, index);
      else if (list->type == LONG_LIST)
	longlist_remove(list->data, index);
    }
  else
    fprintf(stderr, "[LibSharp] list_remove: list is null.\n");
}
