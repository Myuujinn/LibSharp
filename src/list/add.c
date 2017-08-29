/*
** add.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 11:59:03 2017 Victor LE DANTEC
** Last update Tue Aug 29 19:07:19 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"
#include "list.h"

static void	strlist_add(t_strlist *list, char *string)
{
  char		**newlist;

  if ((newlist = malloc(sizeof(char *) * (list->size + 1)))
      == NULL)
    malloc_exit("[LibSharp] strlist_add");
  memcpy(newlist, list->list, sizeof(char *) * list->size);
  newlist[list->size++] = strdup(string);
  if (list->list != NULL)
    free(list->list);
  list->list = newlist;
}

static void	longlist_add(t_longlist *list, long longint)
{
  long		*newlist;

  if ((newlist = malloc(sizeof(long) * (list->size + 1))) == NULL)
    malloc_exit("[LibSharp longlist_add");
  memcpy(newlist, list->list, sizeof(long) * list->size);
  newlist[list->size++] = longint;
  if (list->list != NULL)
    free(list->list);
  list->list = newlist;
}

static void	ptrlist_add(t_ptrlist *list, void *ptr)
{
  void		**newlist;

  if ((newlist = malloc(sizeof(void *) * (list->size + 1))) == NULL)
    malloc_exit("[LibSharp longlist_add");
  memcpy(newlist, list->list, sizeof(void *) * list->size);
  newlist[list->size++] = ptr;
  if (list->list != NULL)
    free(list->list);
  list->list = newlist;
}

void	list_add(t_list *list, void *data)
{
  if (list != NULL && data != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_add(list->data, (char *)data);
      else if (list->type == POINTER_LIST)
	ptrlist_add(list->data, data);
      else if (list->type == LONG_LIST)
	longlist_add(list->data, (long)data);
    }
  else
    fprintf(stderr, "[LibSharp] list_add: null arguments.\n");  
}
