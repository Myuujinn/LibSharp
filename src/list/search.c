/*
** search.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Aug 30 18:31:52 2017 Victor LE DANTEC
** Last update Wed Aug 30 18:45:21 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

static size_t	strlist_search(t_strlist *list, char *string)
{
  size_t	i;

  if (string != NULL)
    {
      i = 0;
      while (list->size > i)
	{
	  if (strcmp(list->list[i], string) == 0)
	  return (i);
	  i++;
	}
    }
  else
    fprintf(stderr, "[LibSharp] strlist_search: string is null.\n");
  return ((size_t)-1);
}

static size_t	ptrlist_search(t_ptrlist *list, void *ptr)
{
  size_t	i;

  if (ptr != NULL)
    {
      i = 0;
      while (list->size > i)
	{
	  if (list->list[i] == ptr)
	    return (i);
	  i++;
	}
    }
  else
    fprintf(stderr, "[LibSharp] ptrlist_search: pointer is null.\n");
  return ((size_t)-1);
}

static size_t	longlist_search(t_longlist *list, long longint)
{
  size_t	i;

  i = 0;
  while (list->size > i)
    {
      if (list->list[i] == longint)
	return (i);
      i++;
    }
  return ((size_t)-1);
}

size_t	list_search(t_list *list, void *data)
{
  if (list != NULL)
    {
      if (list->type == STRING_LIST)
	return (strlist_search(list->data, data));
      else if (list->type == POINTER_LIST)
	return (ptrlist_search(list->data, data));
      else if (list->type == LONG_LIST)
	return (longlist_search(list->data, (long)data));
    }
  else
    fprintf(stderr, "[LibSharp] list_search: list is null.\n");
  return ((size_t)-1);
}
