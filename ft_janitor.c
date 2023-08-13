/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 08:26:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/mylib.h"
#include "includes/structs.h"

// void  ft_data_prep(t_data *data)
// {
//   data->mylexer = NULL;
//   data->cmds = NULL;
//   data->mylexer = NULL;
//   ft_env_setter(data, data->vars, 0);
// }

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
	else if (id == 6)
		_dprintf(2, "ERROR: ambiguous redirect\n");
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
		// 	ft_arr_free((*cmds)->str);
		free((*cmds)->str);
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

void	ft_free_redierctions(t_mylxr *redirections)
{
	t_mylxr	*tmp;

	tmp = redirections;
	while (tmp)
	{
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_decontamination(t_data *data, int n)
{
	t_cmds	*tmp;

	(void) n;
	if (data->paths)
		ft_arr_free(data->paths);
	if (data->env)
		ft_arr_free(data->env);
	if (data->pwd)
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	if (data->old_pwd)
	{
		free(data->old_pwd);
		data->old_pwd = NULL;
	}
	tmp = data->cmds;
	while (tmp)
	{
		ft_arr_free(tmp->str);
		if (tmp->redirections)
			ft_free_redierctions(tmp->redirections);
		free (tmp);
		tmp = tmp->next;
	}
	free(tmp);
}
