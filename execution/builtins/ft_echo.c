/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/22 13:32:59 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_for_n(char *str, int *n)
{
}

void	ft_echo(t_cmds *init)
{
	int i;
	int	n;

	i = 0;
	n = 1;
	
	while (init->str[i])
	{
		printf("%s ", init->str[i]);
		i++;
	}
	if (!n)
		return ;
	printf("\n");
}