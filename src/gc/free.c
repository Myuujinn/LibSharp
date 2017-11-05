/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Free function(s) of the LibSharp garbage collector
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

static void	remove_and_free_ptr_from_gc(node_t *node, uint index)
{
	free(((ptrlist_t *)node->ptr_list->data)->list[index]);
	list_remove(node->ptr_list, index);
}

void	gc_free_ptr(void *ptr)
{
        uint index = 0;

	if (ptr != NULL) {
		for (uint i = 0; g_gc->size > i; i++)
		{
			index = list_search(g_gc->nodes[i].ptr_list, ptr);
			if (index != (uint)-1)
				remove_and_free_ptr_from_gc(&g_gc->nodes[i], index);
		}
	}
}

static void	gc_free_node(node_t *node)
{
	while (*node->ptr_list->size != 0)
		remove_and_free_ptr_from_gc(node, 0);
}

void	gc_free_hash(char *hash)
{
	if (hash != NULL) {
		for (uint i = 1; g_gc->size > i; i++)
			if (strcmp(g_gc->nodes[i].hash, hash) == 0) {
				gc_free_node(&g_gc->nodes[i]);
				return ;
			}
			else
				gc_free_node(&g_gc->nodes[i]);
	}
}

void	gc_free(void)
{
        if (!g_gc)
		return ;
        for (uint i = 0; g_gc->size > i; i++) {
		gc_free_node(&g_gc->nodes[i]);
	        list_destroy(g_gc->nodes[i].ptr_list);
		if (g_gc->nodes[i].hash != NULL)
			free(g_gc->nodes[i].hash);
	}
	free(g_gc->nodes);
	free(g_gc);
	g_gc = NULL;
}
