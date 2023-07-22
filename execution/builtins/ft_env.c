/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:38 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/22 20:26:27 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmds *init)
{
	int	i;
	
	if (init->str[1])
	{
		printf("env: %s: no such file or directory\n", init->str[1]);
		return ;
	}
	i = 0;
	while (init->data->env[i])
	{
		printf("%s\n", init->data->env[i]);
		i++;
	}
}
