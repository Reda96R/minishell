/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:47:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/22 19:56:04 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmds *init)
{
		// printf("%s\n", init->redirections->str);
		// exit (0);
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
		return (ft_env(init), 0);
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
		// printf("%s\n", init->cmds->herdoc);
		init->cmds = init->cmds->next;
	}
}
