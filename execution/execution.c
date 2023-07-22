/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:47:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/22 13:32:44 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmds *init)
{
	if (!strcmp(init->str[0], "pwd"))
		return (ft_pwd(init->data), 0);
	else if (!strcmp(init->str[0], "echo"))
		return (ft_echo(init), 0);
	// else if (!strcmp(init->str[0], "cd"))
	// 	return (ft_cd(, 0))
	// else if (!strcmp(init->str[0], "export"))
	// 	return (ft_export(), 0);
	// else if (!strcmp(init->str[0], "unset"))
	// 	return (ft_unset(), 0);
	else if (!strcmp(init->str[0], "env"))
		return (ft_env(init->data), 0);
	else if (!strcmp(init->str[0], "exit"))
		return (ft_exit(init), 0);
	return (1);
}

void	ft_execution(t_data *init)
{
	if (!init->cmds)
		return ;
	init->cmds->data = init;
	while (init->cmds)
	{
		is_builtin(init->cmds);
		// if (!init->pipes)
		// 	one_cmd(init);
		// else
		// 	multiple_cmds(init);
		init->cmds = init->cmds->next;
	}
}
