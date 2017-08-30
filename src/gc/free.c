/*
** free.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 21:27:31 2017 Victor LE DANTEC
** Last update Wed Aug 30 19:34:51 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

static void	remove_and_free_ptr_from_gc(t_node *node, size_t index)
{
  free(((t_ptrlist *)node->ptr_list->data)->list[index]);
  list_remove(node->ptr_list, index);
}

void		gc_free_ptr(void *ptr)
{
  size_t	i;
  size_t	index;

  if (ptr != NULL)
    {
      i = 0;
      while (g_gc->size > i)
	{
	  if ((index = list_search(g_gc->nodes[i].ptr_list, ptr)) != (size_t)-1)
	    remove_and_free_ptr_from_gc(&g_gc->nodes[i], index);
	  i++;
	}
    }
}

static void	gc_free_node(t_node *node)
{
  while (*node->ptr_list->size != 0)
    remove_and_free_ptr_from_gc(node, 0);
}

void		gc_free_hash(char *hash)
{
  size_t	i;

  i = 1;
  if (hash != NULL)
    while (g_gc->size > i)
      {
	if (strcmp(g_gc->nodes[i].hash, hash) == 0)
	  {
	    gc_free_node(&g_gc->nodes[i]);
	    return ;
	  }
	i++;
      }
  else
    gc_free_node(&g_gc->nodes[i]);
}

void		gc_free()
{
  size_t	i;

  if (!g_gc)
    return ;
  i = 0;
  while (g_gc->size > i)
    {
      gc_free_node(&g_gc->nodes[i]);
      list_destroy(g_gc->nodes[i].ptr_list);
      if (g_gc->nodes[i].hash != NULL)
	free(g_gc->nodes[i].hash);
      i++;
    }
  free(g_gc->nodes);
  free(g_gc);
  g_gc = NULL;
}
