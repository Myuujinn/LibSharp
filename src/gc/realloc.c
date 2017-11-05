/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Realloc function of the LibSharp's garbage collector
*/

#include <string.h>
#include "libsharp.h"

void	*gc_realloc(void *ptr, size_t oldsize, size_t size, char *hash)
{
	void	*realloc_ptr;

	if (ptr == NULL)
		return (gc_malloc(size, hash));
	if (size == 0)
		return (ptr);
	realloc_ptr = gc_malloc(size, hash);
	memcpy(realloc_ptr, ptr, oldsize);
	gc_free_ptr(ptr);
	return (realloc_ptr);
}
