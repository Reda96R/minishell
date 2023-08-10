/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:57:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/10 09:51:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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

void	ft_execution(t_data *init)
{
	if (init->cmds)
	{
		g_var.data->std_in = dup(0);
		if (g_var.data->std_in == -1)
			ft_error_exec(7, NULL, 0);
		g_var.data->std_out = dup(1);
		if (g_var.data->std_out == -1)
			ft_error_exec(7, NULL, 0);
		init->cmds->str = ft_expander(init, init->cmds->str, 2);
		if (!init->pipes)
			one_cmd(init->cmds);
		else
			multiple_cmds(init);
	}
}
