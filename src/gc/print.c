/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Print function of the LibSharp's garbage collector
*/

#include <stdio.h>
#include "libsharp.h"

void	gc_print(void)
{
	if (g_gc) {
		printf("--- LibSharp Garbage Collector ---\n");
		for (uint i = 0; g_gc->size > i; i++) {
			printf("%s = ", g_gc->nodes[i].hash);
			list_print(g_gc->nodes[i].ptr_list);
		}
	} else
		fprintf(stderr, "[LibSharp] gc_print: garbage collector is null.\n");
}
