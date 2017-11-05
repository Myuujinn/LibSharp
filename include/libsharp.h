/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Header file for the library
*/

#pragma once

// Epitech tradition to exit 84 so I map it to EXIT_FAILURE for easier use.
// "undef-ing" the standard library if needed.
#undef  EXIT_FAILURE
#define EXIT_FAILURE	84

#include "list.h"

typedef struct	node_s
{
  char		*hash;
  list_t	*ptr_list;
}		node_t;

typedef struct	garbage_collector_s
{
  uint		size;
  node_t	*nodes;
}		garbage_collector_t;

// From Java. It's really useful.
typedef unsigned long long	iterator_t;

extern garbage_collector_t	*g_gc;

void	libsharp_error(char *error);
void	malloc_exit(char *source);
void	error_exit(char *source, char *error);
int	error_return(char *source, char *error, int status);
void	*error_ptr(char *source, char *error, void *ptr);

void	*gc_malloc(size_t size, char *hash);
void	*gc_realloc(void *ptr, size_t oldsize, size_t newsize, char *hash);
void	gc_free_ptr(void *ptr);
void	gc_free_hash(char *hash);
void	gc_free(void);
void	gc_print(void);
