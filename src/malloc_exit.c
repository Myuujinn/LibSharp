/*
** malloc_exit.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Aug 24 19:18:26 2017 Victor LE DANTEC
** Last update Sun Aug 27 11:56:34 2017 Victor LE DANTEC
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

void	malloc_exit(char *source)
{
  if (source != NULL)
    {
      write(STDERR_FILENO, source, strlen(source));
      write(STDERR_FILENO, ": Memory allocation failed.\n", 29);
    }
  exit(EXIT_FAILURE);
}
