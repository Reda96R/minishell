/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/02 19:23:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    first_child(t_cmds *cmd, int *pp)
{
	char	*path;
	pid_t	pid;

    cmd->fd_out = pp[1];
    ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!is_builtin(cmd))
			return ;
		path = path_getter(cmd);
		if (dup2(cmd->fd_in, 0) == -1)
			ft_error_exec(5, NULL);
		if (dup2(cmd->fd_out, 1) == -1)
			ft_error_exec(5, NULL);
		execve(path, cmd->str, g_var.data->env);
	}
	if (dup2(pp[0], 0) == -1)
		ft_error_exec(5, NULL);
	close(cmd->fd_in);
	close(cmd->fd_out);
    waitpid(pid, NULL, 0);
}

void	mid_childs(t_cmds *cmd)
{
	char	*path;
	pid_t	pid;
	int		pp[2];

	pipe(pp);
	cmd->fd_in = pp[0];
    cmd->fd_out = pp[1];
	ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!is_builtin(cmd))
			return ;
		path = path_getter(cmd);
		if (dup2(cmd->fd_in, 0) == -1)
			ft_error_exec(5, NULL);
		if (dup2(cmd->fd_out, 1) == -1)
			ft_error_exec(5, NULL);
		execve(path, cmd->str, g_var.data->env);
	}
	if (dup2(pp[0], 0) == -1)
		ft_error_exec(5, NULL);
    close(cmd->fd_in);
	close(cmd->fd_out);
    waitpid(pid, NULL, 0);
}

void	last_child(t_cmds *cmd)
{
	char	*path;
	pid_t	pid;
	int		pp[2];

	pipe(pp);
	cmd->fd_in = pp[0];
	ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!is_builtin(cmd))
			return ;
		path = path_getter(cmd);
		if (dup2(cmd->fd_in, 0) == -1)
			ft_error_exec(5, NULL);
		if (dup2(cmd->fd_out, 1) == -1)
			ft_error_exec(5, NULL);
		execve(path, cmd->str, g_var.data->env);
	}
	close(cmd->fd_in);
	close(cmd->fd_out);
    waitpid(pid, NULL, 0);
}

void	multiple_cmds(t_data *init)
{
	int	pp[2];

    pipe(pp);
    first_child(init->cmds, pp);
	init->cmds = init->cmds->next;
	while (init->cmds->next)
	{
		mid_childs(init->cmds);
		init->cmds = init->cmds->next;
	}
	last_child(init->cmds);
	if (dup2(g_var.data->std_in, 0) == -1)
		ft_error_exec(5, NULL);
	if (dup2(g_var.data->std_out, 1) == -1)
		ft_error_exec(5, NULL);
}
