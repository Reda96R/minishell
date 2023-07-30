/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:38 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/29 17:04:42 by yes-slim         ###   ########.fr       */
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
		printf("%s\n", g_var.data->env[i]);
		i++;
	}
}
