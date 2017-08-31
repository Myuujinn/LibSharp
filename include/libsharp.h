/*
** libsharp.h for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Aug 24 19:17:02 2017 Victor LE DANTEC
** Last update Thu Aug 31 18:50:05 2017 Victor LE DANTEC
*/

#pragma once

#undef  EXIT_FAILURE
#define EXIT_FAILURE	84

#include "list.h"

typedef struct	s_node
{
  char		*hash;
  t_list	*ptr_list;
}		t_node;

typedef struct	s_garbage_collector
{
  size_t	size;
  t_node	*nodes;
}		t_garbage_collector;

extern t_garbage_collector	*g_gc;

void	malloc_exit(char *source);
void	error_exit(char *source, char *error);
int	error_return(char *source, char *error, int status);
void	*error_ptr(char *source, char *error, void *ptr);

void	*gc_malloc(size_t size, char *hash);
void	*gc_realloc(void *ptr, size_t oldsize, size_t newsize, char *hash);
void	gc_free_ptr(void *ptr);
void	gc_free_hash(char *hash);
void	gc_free();
void	gc_print();
