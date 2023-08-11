/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:51:55 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/11 02:37:27 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_single_quote(char *cmd, int *j, char r)
{
	*j += 1;
	while (cmd[*j] && cmd[*j] != r)
	{
		if (cmd[*j] == '\"')
				cmd[*j] = -2;
		else if (cmd[*j] == '$')
				cmd[*j] = -3;
		*j += 1;
	}
	if (cmd[*j] == r)
			*j += 1;
	return (cmd);
}

char	*ft_double_quote(char *cmd, int *j, char r)
{
	while (cmd[*j] && cmd[*j] != r)
	{
		if (cmd[*j] == '$')
		{
			if (cmd[*j + 1] == '\"' || cmd[*j + 1] == '\''
				|| !ft_isalnum(cmd[*j + 1]))
			{
				cmd[*j] = -3;
				*j += 1;
			}
			else if (cmd[*j + 1] != '\'' && cmd[*j + 1] != '\"'
				&& cmd[*j + 1] != '$')
				cmd = ft_gold_finder(g_var.data, cmd);
		}
		else
		{
			if (cmd[*j] == '\'')
				cmd[*j] = -1;
			*j += 1;
		}
	}
	if (cmd[*j] == r)
		*j += 1;
	return (cmd);
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

	r = cmd[*j];
	if (g_var.hd_expansion && quote_protect)
		return (ft_protect_quotes(cmd, j));
	if (r == '\'')
		cmd = ft_single_quote(cmd, j, r);
	else
	{
		*j += 1;
		if (ft_dollar_s(ft_substr(cmd, *j, ft_strlen(cmd))) && cmd[*j] != r)
			cmd = ft_double_quote(cmd, j, r);
		else
		{
			while (cmd[*j] && cmd[*j] != r)
			{
				if (cmd[*j] == '\'')
					cmd[*j] = -1;
				*j += 1;
			}
			if (cmd[*j] == r)
				*j += 1;
		}
	}
	return (cmd);
}
