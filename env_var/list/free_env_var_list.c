/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_var_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:48:07 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/26 11:04:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

void	free_env_var_list(t_env_var_list **env_var_list)
{
	ft_lstclear(env_var_list, free_env_var);
}
