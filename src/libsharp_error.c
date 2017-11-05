/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Prints a LibSharp related error.
*/

#include <stdio.h>

void	libsharp_error(char *error)
{
	if (error != NULL)
		fprintf(stderr, "[LibSharp] %s\n", error);
}
