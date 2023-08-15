/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 17:47:00 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_vars *init)
{
	if (init->key)
		free(init->key);
	if (init->value)
		free(init->value);
	free(init);
}

void	del_var(t_vars *tmp)
{
	t_vars	*ftmp;

	if (!tmp->prev)
	{
		g_var.data->vars = tmp->next;
		g_var.data->vars->prev = NULL;
	}
	else if (!tmp->next)
		tmp->prev->next = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	ftmp = tmp;
	tmp = tmp->next;
	ft_free(ftmp);
}

void	ft_unset(t_cmds *init)
{
	t_vars	*tmp;
	int		i;

	i = 1;
	while (init->str[i])
	{
		tmp = g_var.data->vars;
		while (tmp)
		{
			if (!_strcmp(init->str[i], tmp->key))
			{
				del_var(tmp);
				break ;
			}
			else
				tmp = tmp->next;
		}
		i++;
	}
	g_var.exit_status = 0;
}
