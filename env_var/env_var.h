/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/11 14:20:43 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

# include "../libft/libft.h"

typedef t_list	t_env_var_list;

typedef struct s_env_var
{
	char	*key;
	char	*value;
}	t_env_var;

// env_var_list
t_env_var_list	*create_env_var_list(char **envp);
void			free_env_var_list(t_env_var_list **env_var_list);

t_env_var_list	*find_env_var_node(char *key, t_env_var_list *env_var_list);
t_env_var		*find_env_var(char *key, t_env_var_list *env_var_list);
char			*get_env_value(char *key, t_env_var_list *env_var_list);

t_env_var_list	*set_env_var(char *key, char *value,
					t_env_var_list **env_var_list);

void			del_env_var(char *key, t_env_var_list **env_var_list);

void			print_env_var_list(t_env_var_list *env_var_list);

char			**get_envp_arr(t_env_var_list *env_var_list);

// env_var
t_env_var		*create_env_var(char *key, char *value);
void			free_env_var(void *env_var);
int				is_valid_key(char *key);

// utils
char			*get_key_part_from_envp(char *env_var_line);
char			*get_value_part_from_envp(char *env_var_line);
char			**split_env_var_line(char *env_var_line);

#endif
