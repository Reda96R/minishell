/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:07:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 09:16:53 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_normal_expand(char **cmd, int n, int *j, int i)
{
	char	*str;

	if (!ft_isalnum(cmd[i][*j + 1]) && cmd[i][*j + 1] != '_' &&
					cmd[i][*j + 1] != '?')
	{
		cmd[i][*j] = -3;
		*j += 1;
	}
	else
	{
		str = ft_gold_finder(g_var.data, cmd[i]);
		if (!i && !str[0] && !cmd[i + 1] && n)
			ft_shell_reset(g_var.data);
		free(cmd[i]);
		if (!ft_strlen(str))
		{
			free(str);
			cmd[i] = ft_empty();
		}
		else
			cmd[i] = str;
		if (cmd[i] && cmd[i][*j] != '\'' && cmd[i][*j] != '\"')
			*j += 1;
	}
	return (cmd[i]);
}

int	ft_spotter(char **cmd)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] != -4)
			j++;
		i++;
	}
	return (j);
}
