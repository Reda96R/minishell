/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:59:29 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/14 17:06:15 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_infile(t_mylxr *file)
{
	int	fd;

	fd = open(file->str, O_RDONLY);
	if (fd == -1)
	{
		if (access(file->str, F_OK) == -1)
			ft_error_exec(1, file->str, 2);
		else
			ft_error_exec(3, file->str, 2);
	}
	return (fd);
}

int	check_outfile(t_mylxr *file)
{
	int	fd;

	if (file->token_id == GREATER)
		fd = open(file->str, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (file->token_id == D_GREATER)
		fd = open(file->str, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (fd == -1)
		ft_error_exec(3, file->str, 2);
	return (fd);
}

void	ft_check_files(t_cmds *cmd)
{
	t_mylxr	*tmp;

	tmp = cmd->redirections;
	// printf("%d %d\n", cmd->fd_in, cmd->fd_out);
	while (tmp)
	{
		if (cmd->fd_in == -1 || cmd->fd_out == -1)
			return ;
		if (cmd->fd_in != 0)
			close(cmd->fd_in);
		if (cmd->fd_out != 1)
			close(cmd->fd_out);
		if (tmp->token_id == GREATER || tmp->token_id == D_GREATER)
			cmd->fd_out = check_outfile(tmp);
		else if (tmp->token_id == LESS)
			cmd->fd_in = check_infile(tmp);
		else if (tmp->token_id == D_LESS)
			cmd->fd_in = ft_heredoc(tmp);
		tmp = tmp->next;
	}
	// printf("%d %d\n", cmd->fd_in, cmd->fd_out);
}
