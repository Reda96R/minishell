/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/06 20:34:36 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_cmds *cmd)
{
	char *path;
	
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
	exit (127);
}

void    first_child(t_cmds *cmd, int *pp)
{
	pid_t	pid;
	
	cmd->fd_out = pp[1];
    ft_check_files(cmd);
	if (!cmd->str[0] || cmd->fd_in == -1 || cmd->fd_out == -1)
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL, 0);
	if (pid == 0)
	{
		close(pp[0]);
		execute(cmd);
	}
	close(pp[1]);
	if (dup2(pp[0], 0) == -1)
		ft_error_exec(5, NULL, 0);
	close(pp[0]);
}

void	mid_childs(t_cmds *cmd)
{
	pid_t	pid;
	int		pp[2];

	if (pipe(pp) == -1)
		ft_error_exec(6, NULL, 0);
    cmd->fd_out = pp[1];
	ft_check_files(cmd);
	if (!cmd->str[0] || cmd->fd_in == -1 || cmd->fd_out == -1)
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL, 0);
	if (pid == 0)
	{
		close(pp[0]);
		execute(cmd);
	}
    close(cmd->fd_in);
	if (dup2(pp[0], 0) == -1)
		ft_error_exec(5, NULL, 0);
	close(cmd->fd_out);
}

int	last_child(t_cmds *cmd)
{
	pid_t	pid;

	ft_check_files(cmd);
	if (!cmd->str[0] || cmd->fd_in == -1 || cmd->fd_out == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL, 0);
	if (pid == 0)
		execute(cmd);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	return (pid);
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
	while (wait(NULL) != -1);
}

void	multiple_cmds(t_data *init)
{
	int	pid;
	int	pp[2];

    if (pipe(pp) == -1)
		ft_error_exec(6, NULL, 0);
    first_child(init->cmds, pp);
	init->cmds = init->cmds->next;
	while (init->cmds->next)
	{
		mid_childs(init->cmds);
		init->cmds = init->cmds->next;
	}
	pid = last_child(init->cmds);
	ft_wait(pid);
	if (dup2(g_var.data->std_in, 0) == -1)
		ft_error_exec(5, NULL, 0);
	if (dup2(g_var.data->std_out, 1) == -1)
		ft_error_exec(5, NULL, 0);
}
