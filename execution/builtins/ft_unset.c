/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/06 10:17:07 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *str)
{
	int	i;
	
	i = 0;
	if (!_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] && str[i] != '=')
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
		if (!strcmp(tmp->key, str))
			tmp->prev->next = tmp->next; 
			// printf("%s\n", tmp->prev->key);
		tmp = tmp->next;
	}
}
void	ft_unset(t_cmds *init)
{
	int	i;

	i = 1;
	while(init->str[i])
	{
		if (ft_check(init->str[i]))
			del_var(init->str[i]);
		else
			ft_builtins_error(9, init->str[i]);
		i++;
	}
}
