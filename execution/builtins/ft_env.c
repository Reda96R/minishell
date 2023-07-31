/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:38 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 17:20:42 by YOUNES           ###   ########.fr       */
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
	while (g_var.data->env[i])
	{
		_dprintf(init->fd_out, "%s\n", g_var.data->env[i]);
		i++;
	}
}
