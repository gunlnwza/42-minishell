/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:31:11 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/25 12:03:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "builtin.h"

// valid flag: -[n]{1,}
static int	is_n_flag(char *str)
{
	if (*str != '-')
		return (FALSE);
	str++;
	if (*str == '\0')
		return (FALSE);
	while (*str)
	{
		if (*str != 'n')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static void	apply_options(int argc, char **argv, int *i, int *put_newline)
{
	while (*i < argc)
	{
		if (!is_n_flag(argv[*i]))
			break ;
		*put_newline = FALSE;
		(*i)++;
	}
}

static void	print_arguments(int argc, char **argv, int *i)
{
	while (*i < argc)
	{
		printf("%s", argv[*i]);
		if (*i < argc - 1)
			printf(" ");
		(*i)++;
	}
}

t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data)
{
	int		put_newline;
	int		i;

	(void) data;
	put_newline = TRUE;
	i = 1;
	if (i < argc)
	{
		apply_options(argc, argv, &i, &put_newline);
		print_arguments(argc, argv, &i);
	}
	if (put_newline)
		printf("\n");
	return (SUCCESS);
}
