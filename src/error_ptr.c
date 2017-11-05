/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Function that returns a pointer with an error message
*/

#include <stdio.h>

void	*error_ptr(char *source, char *error, void *ptr)
{
	if (source != NULL && error != NULL)
		fprintf(stderr, "%s: %s\n", source, error);
	return (ptr);
}
