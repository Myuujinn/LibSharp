/*
** swap.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 20:16:12 2017 Victor LE DANTEC
** Last update Sun Aug 27 20:53:38 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "list.h"

void	strlist_swap(t_strlist *list, size_t index, size_t index2)
{
  char	*save;

  if (index >= list->size || index2 >= list->size)
    fprintf(stderr, "[LibSharp] strlist_swap: out of bounds.\n");
  else if (index == index2)
    fprintf(stderr, "[LibSharp] strlist_swap: same index.\n");
  else
    {
      save = list->list[index];
      list->list[index] = list->list[index2];
      list->list[index2] = save;
    }
}

void	longlist_swap(t_longlist *list, size_t index, size_t index2)
{
  long	save;

  if (index >= list->size || index2 >= list->size)
    fprintf(stderr, "[LibSharp] strlist_swap: out of bounds.\n");
  else if (index == index2)
    fprintf(stderr, "[LibSharp] strlist_swap: same index.\n");
  else
    {
      save = list->list[index];
      list->list[index] = list->list[index2];
      list->list[index2] = save;
    }
}

void	list_swap(t_list *list, size_t index, size_t index2)
{
  if (list != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_swap(list->data, index, index2);
      else if (list->type == LONG_LIST)
	longlist_swap(list->data, index, index2);
    }
  else
    fprintf(stderr, "[LibSharp] list_swap: list is null.\n");
}