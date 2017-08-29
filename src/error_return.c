/*
** error_return.c for LibSharp in /home/myujinn/LibSharp
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Aug 29 20:23:07 2017 Victor LE DANTEC
** Last update Tue Aug 29 20:26:03 2017 Victor LE DANTEC
*/

#include <stdio.h>

int	error_return(char *source, char *error, int status)
{
  if (source != NULL && error != NULL)
    fprintf(stderr, "%s: %s\n", source, error);
  return (status);
}
