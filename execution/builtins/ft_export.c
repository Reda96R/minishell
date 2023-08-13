/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/13 12:14:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_export(char *str);
void	_print(t_cmds *init);
void	add_var(const char *ident);

void	_free(char **arr)
{
	if (arr[0])
		free(arr[0]);
	if (arr[1])
		free(arr[1]);
	if (arr)
		free(arr);
}

void	ft_add(t_vars *tmp, char id, char **str)
{
	if (id == '+')
	tmp->value = _strjoin(tmp->value, str[1]);
	else
	{
		free(tmp->value);
		tmp->value = _strdup(str[1]);
	}
	return ;
}

void	ft_export(t_cmds *init)
{
	int	i;

	if (!init->str[1])
	{
		_print(init);
		return ;
	}
	i = 1;
	// for (int i=0; init->str[i]; i++)
	// 	printf("%s\n", init->str[i]);
	// exit (0);
	while (g_var.data->vars && init->str[i])
	{
		if (ft_check_export(init->str[i]))
			add_var(init->str[i]);
		else
			ft_builtins_error(8, init->str[i]);
		i++;
	}
	g_var.exit_status = 0;
}
