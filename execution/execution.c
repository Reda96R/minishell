/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:47:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 07:30:02 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmds *init)
{
	if (!strcmp(init->str[0], "pwd"))
		return (ft_pwd(g_var.data), 0);
	if (!strcmp(init->str[0], "oldpwd"))
		printf("%s\n", g_var.data->old_pwd);
	else if (!strcmp(init->str[0], "echo"))
		return (ft_echo(init), 0);
	else if (!strcmp(init->str[0], "cd"))
		return (ft_cd(init), 0);
	// else if (!strcmp(init->str[0], "export"))
		// return (ft_export(), 0);
	// else if (!strcmp(init->str[0], "unset"))
		// return (ft_unset(), 0);
	else if (!strcmp(init->str[0], "env"))
		return (ft_env(init), 0);
	else if (!strcmp(init->str[0], "exit"))
		return (ft_exit(init), 0);
	return (1);
}

void	ft_execution(t_data *init)
{
	if (init->cmds)
	{
		init->cmds->str = ft_expander(init, init->cmds->str);
		if (!init->pipes)
			one_cmd(init->cmds);
		else
		{
			while (init->cmds)
			{
				// multiple_cmds(init);
				// printf("%s\n", init->cmds->herdoc);
				init->cmds = init->cmds->next;
			}
		}
	}
}
