/*
** list.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Aug 21 19:45:31 2017 Victor LE DANTEC
** Last update Mon Aug 28 07:49:47 2017 Victor LE DANTEC
*/

#include <stdlib.h>
#include "libsharp.h"
#include "list.h"

static t_strlist	*stringlist_create()
{
  t_strlist		*list;

  if ((list = malloc(sizeof(t_strlist))) == NULL)
    malloc_exit("[LibSharp] stringlist_create");
  list->size = 0;
  list->list = NULL;
  return (list);
}

static t_longlist	*longlist_create()
{
  t_longlist		*list;

  if ((list = malloc(sizeof(t_longlist))) == NULL)
    malloc_exit("[LibSharp] stringlist_create");
  list->size = 0;
  list->list = NULL;
  return (list);
}

static void	allocate_list(t_list *list)
{
  if (list->type == STRING_LIST)
    list->data = stringlist_create();
  else if (list->type == LONG_LIST)
    list->data = longlist_create();
}

t_list		*list_create(t_list_types data_type)
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (data_type > LONG_LIST)
    error_exit("[LibSharp] list_create", "data type unknown.");
  list->type = data_type;
  allocate_list(list);
  list->size = &(((t_strlist *)list->data)->size);
  return (list);
}
