/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/01 19:47:58 by YOUNES           ###   ########.fr       */
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
	if (!is_builtin(cmd))
		return ;
	path = path_getter(cmd);
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
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

void	mid_childs(t_cmds *cmd, int *pp)
{
	char	*path;
	pid_t	pid;

    cmd->fd_in = pp[0];
    cmd->fd_out = pp[1];
	ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	if (!is_builtin(cmd))
		return ;
	path = path_getter(cmd);
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
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

void	last_child(t_cmds *cmd, int *pp)
{
	char	*path;
	pid_t	pid;

    cmd->fd_in = pp[0];
	ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	if (!is_builtin(cmd))
		return ;
	path = path_getter(cmd);
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
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
    t_cmds *tmp;

    pipe(pp);
    tmp = init->cmds;
    first_child(tmp, pp);
	tmp = tmp->next;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		mid_childs(tmp, pp);
		tmp = tmp->next;
	}
	last_child(tmp, pp);
}
