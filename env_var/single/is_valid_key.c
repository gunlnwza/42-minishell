/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:37:20 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:32:11 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

// start with [A-Za-z] or '_'
// follow with [0-9A-Za-z] or '_'
int	is_valid_key(char *key)
{
	if (!(ft_isalpha(*key) || *key == '_'))
		return (FALSE);
	key++;
	while (*key)
	{
		if (!(ft_isalnum(*key) || *key == '_'))
			return (FALSE);
		key++;
	}
	return (TRUE);
}
