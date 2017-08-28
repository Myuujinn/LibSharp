/*
** error_exit.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Aug 24 19:18:26 2017 Victor LE DANTEC
** Last update Sun Aug 27 11:56:12 2017 Victor LE DANTEC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsharp.h"

void	error_exit(char *source, char *error)
{
  if (source != NULL && error != NULL)
    fprintf(stderr, "%s: %s\n", source, error);
  exit(EXIT_FAILURE);
}
