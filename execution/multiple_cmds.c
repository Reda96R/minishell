/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:36:23 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 20:49:02 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*first_child(t_cmds *cmd)
{
	char	*path;
	pid_t	pid;
	int		pp[2];

	pipe(pp);
	ft_check_files(cmd);
	if (!cmd->str[0])
		return ;
	if (!is_builtin(cmd))
		return ;
	path = path_getter(cmd);
	dup2(cmd->fd_out, pp[1]);
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
	return (pp);
}

int	mid_childs(t_cmds *cmd, int *pp)
{
	
}

void	last_child(t_cmds *cmd, int *pp)
{
	
}

void	multiple_cmds(t_data *init)
{
	int	*pipe;

	pipe = first_child(init->cmds);
	while (init->cmds->next)
	{
		pipe = mid_childs(init->cmds, pipe);
		init->cmds = init->cmds->next;
	}
	last_child(init->cmds, pipe);
}
