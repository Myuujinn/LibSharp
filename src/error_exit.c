/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** A simple exit with error function
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
