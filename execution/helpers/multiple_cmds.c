/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/12 19:13:23 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_child(t_cmds *cmd, int *pp);
void	mid_childs(t_cmds *cmd, int *pp);
int		last_child(t_cmds *cmd);

void	execute(t_cmds *cmd)
{
	char	*path;

	if (cmd->fd_in == -1 || cmd->fd_out == -1)
		exit(1);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!is_builtin(cmd))
		exit(0);
	path = path_getter(cmd);
	if (dup2(cmd->fd_in, 0) == -1)
		ft_error_exec(5, NULL, -1);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (dup2(cmd->fd_out, 1) == -1)
		ft_error_exec(5, NULL, -1);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	execve(path, cmd->str, g_var.data->env);
		perror("<?>: execve");
		exit(127);
}

void	ft_wait(int pid)
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
	while (wait(NULL) != -1)
		continue ;
}

void	multiple_cmds(t_data *init)
{
	int	pid;
	int	pp[2];
	int	pi[2];

	if (pipe(pp) == -1)
		ft_error_exec(6, NULL, 0);
	first_child(init->cmds, pp);
	init->cmds = init->cmds->next;
	while (init->cmds->next)
	{
		if (pipe(pi) == -1)
		{
			dup2(g_var.data->std_in, 0);
			ft_error_exec(6, NULL, 0);
		}
		mid_childs(init->cmds, pi);
		init->cmds = init->cmds->next;
	}
	pid = last_child(init->cmds);
	ft_wait(pid);
	if (dup2(g_var.data->std_in, 0) == -1)
		ft_error_exec(5, NULL, 0);
	if (dup2(g_var.data->std_out, 1) == -1)
		ft_error_exec(5, NULL, 0);
}
