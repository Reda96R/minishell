/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:32:30 by YOUNES            #+#    #+#             */
/*   Updated: 2023/08/07 20:21:55 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_hd(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
			g_var.exit_status = 131;
		if (WTERMSIG(status) == 2)
			g_var.exit_status = 130;
	}
}
int	ft_heredoc(t_mylxr *del)
{
	int	pp[2];
	char *str;

	pipe(pp);
	pid_t pid = fork();
	if (pid == 0)
	{	
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			str = readline("> ");
			if (!str || !_strcmp(del->str, str))
				exit(1);
			_dprintf(pp[1], "%s\n", str);
			free(str);
		}
	}
	ft_wait_hd(pid);
	close(pp[1]);
	return (pp[0]);
}
