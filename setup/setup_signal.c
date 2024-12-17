/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:38:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/12/17 15:15:23 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "../builtin/builtin.h"

static void	ft_sigint(int signal)
{
	if (signal != SIGINT)
		return ;
	if (g_signal == EXECUTE_MODE)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("^C\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal = 128 + signal;	
	}
}

static void	ft_sigquit(int signal)
{
	if (signal != SIGQUIT)
		return ;
	if (g_signal == EXECUTE_MODE)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	set_signal_action(int signum, void (*func)(int), int flags)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = func;
	sa.sa_flags = flags;
	if (sigemptyset(&sa.sa_mask) < 0 || sigaction(signum, &sa, NULL) < 0)
		ft_putstr_fd("set_signal_action\n", STDERR_FILENO);
}

void	setup_signal(void)
{
	set_signal_action(SIGQUIT, ft_sigquit, SA_RESTART);
	set_signal_action(SIGINT, ft_sigint, SA_RESTART | SA_SIGINFO);
}
