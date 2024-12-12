/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:44:21 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/10 17:48:33 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

void	del_env_var(char *key, t_env_var_list **env_var_list)
{
	t_list	*matched_node;

	matched_node = find_env_var_node(key, *env_var_list);
	if (matched_node == NULL)
		return ;
	ft_lstdelone(matched_node, free_env_var);
}
