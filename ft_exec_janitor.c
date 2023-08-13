/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_janitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:42:27 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/12 21:37:51 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins_error(int id, char *str)
{
	_dprintf(2, "\033[0;31m");
	if (id == 1)
	{
		_dprintf(2, "cd: error retrieving current directory: getcwd: cannot ");
		_dprintf(2, "access parent directories: No such file or directory\n");
	}
	else if (id == 2)
		_dprintf(2, "<?>: cd: HOME not set\n");
	else if (id == 3)
		_dprintf(2, "<?>: cd: %s: No such file or directory\n", str);
	else if (id == 4)
		_dprintf(2, "env: %s: no such file or directory\n", str);
	else if (id == 5)
		_dprintf(2, "exit\n<?>: exit: %s: numeric argument required\n", str);
	else if (id == 6)
		_dprintf(2, "exit\n<?>: exit: too many arguments\n");
	else if (id == 7)
		_dprintf(2, "<?>: exit: %s: numeric argument required\n", str);
	else if (id == 8)
		_dprintf(2, "<?>: export: `%s': not a valid identifier\n", str);
	else if (id == 9)
		_dprintf(2, "<?>: unset: `%s': not a valid identifier\n", str);
	g_var.data->color = 0;
}

void	ft_error_exec(int id, char *str, int i)
{
	_dprintf(2, "\033[0;31m");
	if (id == 1)
		_dprintf(2, "<?>: %s: No such file of directory\n", str);
	else if (id == 2)
		_dprintf(2, "<?>: %s: command not found\n", str);
	else if (id == 3)
		_dprintf(2, "<?>: %s: Permission denied\n", str);
	else if (id == 4)
		_dprintf(2, "<?>: fork failed: Resource temporarily unavailable\n");
	else if (id == 5)
		_dprintf(2, "<?>: dup2 failed: Resource temporarily unavailable\n");
	else if (id == 6)
		_dprintf(2, "<?>: pipe failed: Resource temporarily unavailable\n");
	else if (id == 7)
		_dprintf(2, "<?>: dup failed: Resource temporarily unavailable\n");
	else if (id == 8)
		_dprintf(2, "<?>: malloc failed: Resource temporarily unavailable\n");
	g_var.data->color = 0;
	if (i == -1)
		exit(127);
	if (i == 0)
		ft_shell_reset(g_var.data);
	if (i == 2)
		g_var.exit_status = 1;
}
