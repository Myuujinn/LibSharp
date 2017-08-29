/*
** print.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 21:07:10 2017 Victor LE DANTEC
** Last update Tue Aug 29 21:13:49 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include "libsharp.h"

void		gc_print()
{
  size_t	i;

  if (gc)
    {
      printf("--- LibSharp Garbage Collector ---\n");
      i = 0;
      while (gc->size > i)
	{
	  printf("%s = ", gc->nodes[i].hash);
	  list_print(gc->nodes[i].ptr_list);
	  i++;
	}
    }
  else
    fprintf(stderr, "[LibSharp] gc_print: garbage collector is null.\n");
}
