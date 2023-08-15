/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:51:55 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/15 17:58:54 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_single_quote(char *cmd, int *j, char r)
{
	char	*tmp;

	*j += 1;
	tmp = ft_strdup(cmd);
	if (!tmp)
		ft_errors_buster(4, g_var.data);
	if (cmd)
		free (cmd);
	while (tmp[*j] && tmp[*j] != r)
	{
		if (tmp[*j] == '\"')
			tmp[*j] = -2;
		else if (tmp[*j] == '$')
			tmp[*j] = -3;
		*j += 1;
	}
	if (tmp[*j] == r)
		*j += 1;
	return (tmp);
}

char	*ft_double_quote(char *cmd, int *j, char r)
{
	char	*tmp;

	tmp = ft_strdup(cmd);
	if (!tmp)
		ft_errors_buster(4, g_var.data);
	if (cmd)
		free(cmd);
	while (tmp[*j] && tmp[*j] != r)
	{
		if (tmp[*j] == '$')
			tmp = ft_dollar_in_quotes(tmp, j);
		else
		{
			if (tmp[*j] == '\'')
				tmp[*j] = -1;
			*j += 1;
		}
	}
	if (tmp[*j] == r)
		*j += 1;
	return (tmp);
}

char	*ft_protect_quotes(char *cmd, int *j)
{
	while (cmd[*j])
	{
		if (cmd[*j] == '\'')
			cmd[*j] = -1;
		if (cmd[*j] == '\"')
			cmd[*j] = -2;
		*j += 1;
	}
	return (ft_gold_finder(g_var.data, cmd));
}

char	*ft_quote_handler(char *cmd, int *j, int quote_protect)
{
	char	r;
	char	*str;

	str = ft_strdup(cmd);
	if (!str)
		ft_errors_buster(4, g_var.data);
	if (cmd)
		free(cmd);
	r = str[*j];
	if (g_var.hd_expansion && quote_protect)
		return (ft_protect_quotes(str, j));
	if (r == '\'')
		str = ft_single_quote(str, j, r);
	else
	{
		*j += 1;
		if (ft_dollar_s(str + (*j)) && str[*j] != r)
			str = ft_double_quote(str, j, r);
		else
			str = ft_quote_hider(str, j, r);
	}
	return (str);
}

char	*ft_black_box(char *str)
{
	int	i;

	i = 0;
	ft_rm_quote(str, '\'', 1);
	ft_rm_quote(str, '\"', 1);
	ft_rm_quote(str, '$', 1);
	while (str[i])
	{
		if (str[i] == -1)
			str[i] = '\'';
		else if (str[i] == -2)
			str[i] = '\"';
		else if (str[i] == -3)
			str[i] = '$';
		i++;
	}
	return (str);
}
