/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/25 16:47:01 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

void	free_env_var(void *env_var)
{
	t_env_var	*var;

	var = env_var;
	free(var->key);
	free(var->value);
	free(var);
}
