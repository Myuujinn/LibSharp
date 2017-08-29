/*
** error_ptr.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 20:24:31 2017 Victor LE DANTEC
** Last update Tue Aug 29 20:25:26 2017 Victor LE DANTEC
*/

#include <stdio.h>

void	*error_ptr(char *source, char *error, void *ptr)
{
  if (source != NULL && error != NULL)
    fprintf(stderr, "%s: %s\n", source, error);
  return (ptr);
}
