/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:31:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/07 12:00:48 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_one(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_var.exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
		{
			g_var.exit_status = 131;
			printf("Quit: 3\n");
		}
		if (WTERMSIG(status) == 2)
			g_var.exit_status = 130;
	}
}

void	one_cmd(t_cmds *init)
{
	char	*path;
	int		pid;
	
	ft_check_files(init);
	if (!init->str[0])
		return ;
	if (!is_builtin(init))
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL, 0);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		path = path_getter(init);
		if (dup2(init->fd_in, 0) == -1)
			ft_error_exec(5, NULL, -1);
		if (dup2(init->fd_out, 1) == -1)
			ft_error_exec(5, NULL, -1);
		execve(path, init->str, g_var.data->env);
	}
	ft_wait_one(pid);
}
