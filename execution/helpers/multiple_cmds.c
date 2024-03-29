/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 08:57:29 by yes-slim         ###   ########.fr       */
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
	if (path)
		free (path);
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
		g_var.exit_status = 128 + WTERMSIG(status);
	if (g_var.exit_status == 131)
		printf("Quit\n");
	while (wait(NULL) != -1)
		continue ;
}

void	multiple_cmds(t_data *init)
{
	t_cmds	*tmp;
	int		pid;
	int		pp[2];
	int		pi[2];

	if (pipe(pp) == -1)
		ft_error_exec(6, NULL, 0);
	tmp = init->cmds;
	first_child(tmp, pp);
	tmp = tmp->next;
	while (tmp->next)
	{
		if (pipe(pi) == -1)
		{
			dup2(g_var.data->std_in, 0);
			ft_error_exec(6, NULL, 0);
		}
		mid_childs(tmp, pi);
		tmp = tmp->next;
	}
	pid = last_child(tmp);
	ft_wait(pid);
}
