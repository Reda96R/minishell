/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:38 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/13 08:55:18 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmds *init)
{
	int	i;

	if (init->str[1])
	{
		ft_builtins_error(4, init->str[1]);
		return ;
	}
	i = 0;
	if (g_var.data->env)
	{	
		while (g_var.data->env[i])
		{
			_dprintf(init->fd_out, "%s\n", g_var.data->env[i]);
			i++;
		}
	}
}
