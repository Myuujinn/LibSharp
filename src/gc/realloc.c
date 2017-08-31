/*
** realloc.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Aug 31 18:38:59 2017 Victor LE DANTEC
** Last update Thu Aug 31 18:48:37 2017 Victor LE DANTEC
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
