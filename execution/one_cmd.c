/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:31:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/30 22:17:18 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	one_cmd(t_cmds *init)
{
	char	*path;
	pid_t	pid;
	
	ft_check_files(init);
	printf("in:%d-----out%d\n", init->fd_in, init->fd_out);
	if (!init->str[0])
		return ;
	if (!is_builtin(init))
		return ;
	path = path_getter(init);
	pid = fork();
	if (pid == 0)
		execve(path, init->str, g_var.data->env);
	waitpid(pid, NULL, 0);
}
