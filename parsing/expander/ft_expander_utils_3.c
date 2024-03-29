/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:07:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/16 12:50:39 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_all_quotes_hider(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str[i] = -1;
		else if (str[i] == '\"')
			str[i] = -2;
		i++;
	}
	return (str);
}

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
		str = ft_all_quotes_hider(ft_gold_finder(g_var.data, cmd[i]));
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

char	*ft_dollar_in_quotes(char *tmp, int *j)
{
	char	*str;

	if (tmp[*j + 1] != '?' && ((tmp[*j + 1] == '\"' || tmp[*j + 1] == '\''
				|| (!ft_isalnum(tmp[*j + 1]) && tmp[*j + 1] != '_'))))
	{
		tmp[*j] = -3;
		*j += 1;
	}
	else if (tmp[*j + 1] != '\'' && tmp[*j + 1] != '\"'
		&& tmp[*j + 1] != '$')
	{
		str = ft_gold_finder(g_var.data, tmp);
		free(tmp);
		tmp = ft_strdup(str);
		free(str);
	}
	return (tmp);
}

char	*ft_quote_hider(char *str, int *j, int r)
{
	while (str[*j] && str[*j] != r)
	{
		if (str[*j] == '\'')
			str[*j] = -1;
		*j += 1;
	}
	if (str[*j] == r)
		*j += 1;
	return (str);
}
