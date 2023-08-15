/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:31:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 17:52:20 by yes-slim         ###   ########.fr       */
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
		g_var.exit_status = 128 + WTERMSIG(status);
	if (g_var.exit_status == 131)
		printf("Quit\n");
}

void	ft_execute_cmd(t_cmds *init)
{
	char	*path;

	if (init->fd_in == -1 || init->fd_out == -1)
		exit(1);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	path = path_getter(init);
	if (dup2(init->fd_in, 0) == -1)
		ft_error_exec(5, NULL, -1);
	if (dup2(init->fd_out, 1) == -1)
		ft_error_exec(5, NULL, -1);
	execve(path, init->str, g_var.data->env);
	perror("<?>: execve");
	exit(127);
}

void	one_cmd(t_cmds *init)
{
	int		pid;

	ft_check_files(init);
	if (!init->str[0])
	{
		if (init->fd_in != 0)
			close(init->fd_in);
		if (init->fd_out != 1)
			close(init->fd_out);
		return ;
	}
	if (!is_builtin(init))
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL, 0);
	if (pid == 0)
		ft_execute_cmd(init);
	if (init->fd_in != 0)
		close(init->fd_in);
	if (init->fd_out != 1)
		close(init->fd_out);
	ft_wait_one(pid);
}
