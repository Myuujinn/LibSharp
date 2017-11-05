/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Malloc functions of the LibSharp garbage collector
*/

#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

garbage_collector_t *g_gc = NULL;

static void	*allocate_pointer(node_t *node, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		malloc_exit("[LibSharp] allocate_pointer");
	memset(ptr, 0, size);
	list_add(node->ptr_list, ptr);
	return (ptr);
}

static node_t	*create_node(char *hash)
{
	g_gc->nodes = realloc(g_gc->nodes, sizeof(node_t) * ++g_gc->size);
	if (g_gc->nodes == NULL)
		malloc_exit("[LibSharp] create_node");
	if (hash != NULL)
		g_gc->nodes[g_gc->size - 1].hash = strdup(hash);
	else
		g_gc->nodes[g_gc->size - 1].hash = NULL;
	g_gc->nodes[g_gc->size - 1].ptr_list = list_create(POINTER_LIST);
	return (&g_gc->nodes[g_gc->size - 1]);
}

static void	create_garbage_collector(void)
{
	g_gc = malloc(sizeof(garbage_collector_t));
	if (g_gc == NULL)
		malloc_exit("[LibSharp] build_garbage_collector");
	g_gc->size = 0;
	g_gc->nodes = NULL;
	create_node(NULL);
}

static node_t	*get_node(char *hash)
{
	if (g_gc->size != 0) {
		if (hash == NULL)
			return (&g_gc->nodes[0]);
		for (uint i = 1; i < g_gc->size; i++)
			if (strcmp(g_gc->nodes[i].hash, hash) == 0)
				return (&g_gc->nodes[i]);
	}
	return (NULL);
}

void	*gc_malloc(size_t size, char *hash)
{
	node_t	*node = NULL;

	if (!g_gc)
		create_garbage_collector();
	if (size == 0)
		return (NULL);
	node = get_node(hash);
	if (node == NULL && hash != NULL)
		node = create_node(hash);
	return (allocate_pointer(node, size));
}
