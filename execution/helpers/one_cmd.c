/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:31:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/04 09:20:11 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_cmd(t_cmds *init)
{
	char	*path;
	pid_t	pid;
	
	ft_check_files(init);
	if (!init->str[0])
		return ;
	if (!is_builtin(init))
		return ;
	path = path_getter(init);
	pid = fork();
	if (pid == -1)
		ft_error_exec(4, NULL);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (dup2(init->fd_in, 0) == -1)
			ft_error_exec(5, NULL);
		if (dup2(init->fd_out, 1) == -1)
			ft_error_exec(5, NULL);
		execve(path, init->str, g_var.data->env);
	}
	waitpid(pid, NULL, 0);
}
