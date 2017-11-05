/*
** EPITECH PROJECT, 2017
** LibSharp
** File description:
** Function that returns an integer with an error message 
*/

#include <stdio.h>

int	error_return(char *source, char *error, int status)
{
	if (source != NULL && error != NULL)
		fprintf(stderr, "%s: %s\n", source, error);
	return (status);
}
