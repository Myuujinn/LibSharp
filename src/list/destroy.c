/*
** destroy.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 17:25:31 2017 Victor LE DANTEC
** Last update Tue Aug 29 19:09:43 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void	strlist_destroy(t_strlist *list)
{
  size_t	i;

  if (list->list != NULL)
    {
      i = 0;
      while (i < list->size)
	if (list->list[i++] != NULL)
	  free(list->list[i - 1]);
      free(list->list);
    }
  else
    fprintf(stderr, "[LibSharp] strlist_destroy: list data is null.\n");
  free(list);
}

static void	longlist_destroy(t_longlist *list)
{
  if (list->list != NULL)
    free(list->list);
  else
    fprintf(stderr, "[LibSharp] longlist_destroy: list data is null.\n");
  free(list);
}

static void	ptrlist_destroy(t_ptrlist *list)
{
  if (list->list != NULL)
    free(list->list);
  else
    fprintf(stderr, "[LibSharp] ptrlist_destroy: list data is null.\n");
  free(list);
}

void	list_destroy(t_list *list)
{
  if (list != NULL && list->data != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_destroy(list->data);
      else if (list->type == POINTER_LIST)
	ptrlist_destroy(list->data);
      else if (list->type == LONG_LIST)
	longlist_destroy(list->data);
      free(list);
    }
  else
    fprintf(stderr, "[LibSharp] list_destroy: list is null.\n");
}
