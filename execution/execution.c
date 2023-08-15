/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:57:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 17:56:21 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmds *init)
{
	if (!_strcmp(init->str[0], "pwd"))
		return (ft_pwd(init), 0);
	if (!_strcmp(init->str[0], "$?"))
		return (printf("%d\n", g_var.exit_status), 0);
	else if (!_strcmp(init->str[0], "echo"))
		return (ft_echo(init), 0);
	else if (!_strcmp(init->str[0], "cd"))
		return (ft_cd(init), 0);
	else if (!_strcmp(init->str[0], "export"))
		return (ft_export(init), 0);
	else if (!_strcmp(init->str[0], "unset"))
		return (ft_unset(init), 0);
	else if (!_strcmp(init->str[0], "env"))
		return (ft_env(init), 0);
	else if (!_strcmp(init->str[0], "exit"))
		return (ft_exit(init), 0);
	return (1);
}

void	_heredoc(t_data *init)
{
	t_cmds	*cmd;
	t_mylxr	*red;

	cmd = init->cmds;
	while (cmd)
	{
		red = cmd->redirections;
		while (red)
		{
			if (red->token_id == D_LESS)
			{
				if (cmd->fd_in != 0)
					close(cmd->fd_in);
				cmd->fd_in = ft_heredoc(red);
				cmd->hd_id = red->node_id;
			}
			red = red->next;
		}
		cmd = cmd->next;
	}
}

void	ft_execution(t_data *init)
{
	if (init->cmds)
	{
		_heredoc(init);
		if (!init->cmds->next)
			one_cmd(init->cmds);
		else
			multiple_cmds(init);
		if (dup2(g_var.data->std_in, 0) == -1)
			ft_error_exec(5, NULL, 0);
		if (dup2(g_var.data->std_out, 1) == -1)
			ft_error_exec(5, NULL, 0);
	}
}
