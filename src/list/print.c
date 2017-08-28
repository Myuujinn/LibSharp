/*
** print.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Aug 27 17:00:06 2017 Victor LE DANTEC
** Last update Sun Aug 27 17:20:16 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "list.h"

static void	strlist_print(t_strlist *list)
{
  size_t	i;

  i = 0;
  printf("{ ");
  while (i < list->size)
    {
      printf("\"%s\"", (list->list[i++]));
      if (i < list->size)
	printf(", ");
    }
  printf(" }\n");
}

static void	longlist_print(t_longlist *list)
{
  size_t	i;

  i = 0;
  printf("{ ");
  while (i < list->size)
    {
      printf("%ld", (list->list[i++]));
      if (i < list->size)
	printf(", ");
    }
  printf(" }\n");
}

void	list_print(t_list *list)
{
  if (list->type == STRING_LIST)
    strlist_print(list->data);
  else if (list->type == LONG_LIST)
    longlist_print(list->data);
}
