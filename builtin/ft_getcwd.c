/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:25:13 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 16:25:21 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

#define AS_BIG_AS_NECESSARY 0

// return dynamically alloc'ed string of current path
char	*ft_getcwd(void)
{
	char	*path;

	path = getcwd(NULL, AS_BIG_AS_NECESSARY);
	if (path == NULL)
		return (NULL);
	return (path);
}
