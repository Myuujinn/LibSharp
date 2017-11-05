/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Function that exits when there is a malloc error
*/

#include <stdlib.h>
#include <stdio.h>
#include "libsharp.h"

void	malloc_exit(char *source)
{
	if (source != NULL)
		fprintf(stderr, "%s: Memory allocation failed.\n", source);
	exit(EXIT_FAILURE);
}
