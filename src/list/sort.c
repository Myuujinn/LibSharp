/*
** sort.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 20:52:04 2017 Victor LE DANTEC
** Last update Wed Aug 30 18:29:55 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

static void	strlist_sort(t_strlist *list)
{
  size_t	i;
  size_t	j;

  i = 1;
  if (list->size != 0)
    while (i < list->size)
      {
	j = i++;
	while (j > 0 && strcasecmp(list->list[j], list->list[j - 1]) < 0)
	  {
	    strlist_swap(list, j, j - 1);
	    j--;
	  }
      }
}

static void	longlist_sort(t_longlist *list)
{
  size_t	i;
  size_t	j;

  i = 1;
  if (list->size != 0)
    while (i < list->size)
      {
	j = i++;
	while (j > 0 && list->list[j] < list->list[j - 1])
	  {
	    longlist_swap(list, j, j - 1);
	    j--;
	  }
      }
}

void	list_sort(t_list *list)
{
  if (list != NULL)
    {
      if (list->type == STRING_LIST)
	strlist_sort(list->data);
      else if (list->type == LONG_LIST)
	longlist_sort(list->data);
    }
  else
    fprintf(stderr, "[LibSharp] list_sort: list is null.\n");
}
