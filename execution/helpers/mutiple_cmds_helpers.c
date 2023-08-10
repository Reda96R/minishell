/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutiple_cmds_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:35:26 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/10 21:46:01 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_cmds *cmd);
void	ft_wait(int pid);

void	first_child(t_cmds *cmd, int *pp)
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
