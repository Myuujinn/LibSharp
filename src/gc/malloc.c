/*
** malloc.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 20:07:00 2017 Victor LE DANTEC
** Last update Wed Aug 30 19:16:30 2017 Victor LE DANTEC
*/

#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

t_garbage_collector *g_gc = NULL;

static void	*allocate_pointer(t_node *node, size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    malloc_exit("[LibSharp] allocate_pointer");
  list_add(node->ptr_list, ptr);
  return (ptr);
}

static t_node	*create_node(char *hash)
{
  if ((g_gc->nodes = realloc(g_gc->nodes, sizeof(t_node) * ++g_gc->size)) == NULL)
    malloc_exit("[LibSharp] create_node");
  if (hash != NULL)
    g_gc->nodes[g_gc->size - 1].hash = strdup(hash);
  else
    g_gc->nodes[g_gc->size - 1].hash = NULL;
  g_gc->nodes[g_gc->size - 1].ptr_list = list_create(POINTER_LIST);
  return (&g_gc->nodes[g_gc->size - 1]);
}

static void	create_garbage_collector()
{
  if ((g_gc = malloc(sizeof(t_garbage_collector))) == NULL)
    malloc_exit("[LibSharp] build_garbage_collector");
  g_gc->size = 0;
  g_gc->nodes = NULL;
  create_node(NULL);
}

static t_node	*get_node(char *hash)
{
  size_t	i;

  if (g_gc->size != 0)
    {
      if (hash == NULL)
	return (&g_gc->nodes[0]);
      i = 1;
      while (i < g_gc->size)
	{
	  if (strcmp(g_gc->nodes[i].hash, hash) == 0)
	    return (&g_gc->nodes[i]);
	  i++;
	}
    }
  return (NULL);
}

void		*gc_malloc(size_t size, char *hash)
{
  t_node	*node;

  if (!g_gc)
    create_garbage_collector();
  if (size == 0)
    return (error_ptr("[LibSharp] gc_malloc", "size was 0.", NULL));
  if ((node = get_node(hash)) == NULL && hash != NULL)
    node = create_node(hash);
  return (allocate_pointer(node, size));
}
