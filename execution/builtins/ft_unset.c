/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/10 21:30:12 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_vars *init)
{
	free(init->key);
	if (init->value)
		free(init->value);
	free(init);
}

int	ft_check_unset(char *str)
{
	int	i;

	i = 0;
	if (!_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i])
	{
		if (!_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	del_var(char *str)
{
	t_vars	*tmp;

	tmp = g_var.data->vars;
	while (tmp)
	{
		if (!_strcmp(tmp->key, str))
		{
			tmp->prev->next = tmp->next;
			ft_free(tmp);
		}
		tmp = tmp->next;
	}
}

void	ft_unset(t_cmds *init)
{
	int	i;

	i = 1;
	while (init->str[i])
	{
		if (ft_check_unset(init->str[i]))
			del_var(init->str[i]);
		else
			ft_builtins_error(9, init->str[i]);
		i++;
	}
}
