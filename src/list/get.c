/*
** get.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 20:14:40 2017 Victor LE DANTEC
** Last update Tue Aug 29 20:21:55 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "list.h"

void	*list_get(t_list *list, size_t index)
{
  if (list != NULL)
    {
      if (index < *list->size)
	{
	  if (list->type == STRING_LIST)
	    return (((t_strlist *)list->data)->list[index]);
	  else if (list->type == POINTER_LIST)
	    return (((t_ptrlist *)list->data)->list[index]);
	  else if (list->type == LONG_LIST)
	    return ((void *)((t_longlist *)list->data)->list[index]);
	}
      else
	fprintf(stderr, "[LibSharp] list_get: out of bounds.\n");
    }
  fprintf(stderr, "[LibSharp] list_get: list is null.\n");
  return (NULL);
}
