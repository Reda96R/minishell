/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/15 17:59:38 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/mylib.h"
#include "includes/structs.h"

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
	t_mylxr	*tmp0;

	tmp = redirections;
	tmp0 = redirections;
	while (tmp0)
	{
		free(tmp->str);
		tmp->str = NULL;
		tmp0 = tmp0->next;
		free(tmp);
		tmp = tmp0;
	}
	// free(tmp);
	tmp = NULL;
}
