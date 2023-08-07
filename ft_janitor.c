/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/07 17:22:47 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// void  ft_data_prep(t_data *data)
// {
//   data->mylexer = NULL;
//   data->cmds = NULL;
//   data->mylexer = NULL;
//   ft_env_setter(data, data->vars, 0);
// }

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
	else if (id ==  5)
		_dprintf(2, "exit\n<?>: exit: %s: numeric argument required\n", str);
	else if (id == 6)
		_dprintf(2, "exit\n<?>: exit: too many arguments\n");
	else if (id == 7)
		_dprintf(2, "exit\n<?>: exit: %s: numeric argument required\n", str);
	else if (id == 8)
		_dprintf(2, "<?>: export: `%s': not a valid identifier\n", str);
	else if (id == 9)
		_dprintf(2, "<?>: unset: `%s': not a valid identifier\n", str);
	// else if (id == )
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
		exit(1);
	if (i == 0)
		ft_shell_reset(g_var.data);
	if (i == 2)
		g_var.exit_status = 1;
}

void	ft_errors_buster(int id, t_data *data)
{
	(void)data;
	_dprintf(2, "\033[0;31m");
	if (id == 1)
	{
		_dprintf(2, "ERROR: run without argument\n");
		exit (0);
	}
	else if (id == 2)
		_dprintf(2, "ERROR: unmatched quotes\n");
	else if (id == 3)
		_dprintf(2, "syntax error near unexpected token\n");
	else if (id == 4)
		_dprintf(2, "memory error: unable to allocate memory\n");
	else if (id == 5)
		_dprintf(2, "ERROR: unset: not enough arguments\n");
	g_var.data->color = 0;
	ft_shell_reset(data);
}

void	ft_lxr_cleaner(t_mylxr **mylexer)
{
	t_mylxr	*tmp;

	if (!mylexer)
		return ;
	while (*mylexer)
	{
		tmp = (*mylexer)->next;
		if ((*mylexer)->str)
			free((*mylexer)->str);
		free(*mylexer);
		*mylexer = tmp;
	}
	*mylexer = NULL;
}

void	ft_cmd_cleaner(t_cmds **cmds)
{
	t_mylxr	*redirections;
	t_cmds	*tmp;

	if (!cmds)
		return ;
	while (*cmds)
	{
		tmp = (*cmds)->next;
		redirections = (*cmds)->redirections;
		ft_lxr_cleaner(&redirections);
	// if ((*cmds)->str)
	// 		ft_arr_free((*cmds)->str);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
}

t_mylxr	*ft_node_clear(t_mylxr **node)
{
	if ((*node)->str)
	{
		free((*node)->str);
		(*node)->str = NULL;
	}
	free(*node);
	*node = NULL;
	return (NULL);
}
