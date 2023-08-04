/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:53 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/03 18:56:22 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_skipper(char **cmd)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i][j])
			j++;
		i++;
	}
	str = (char **) malloc(sizeof (char *) * j + 1);
	if (!str)
		ft_errors_buster(4, g_var.data);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i][j] != '\0')
			str[j++] = cmd[i];
		i++;
	}
	str[j] = NULL;
	return (str);
}

size_t	ft_dollar_s(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_gold_finder(t_data *data, char *str)
{
	int		i;
	char	*tmp0;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	tmp0 = ft_strdup("\0");
	while (str[i])
	{
		i += ft_digit_skipper(str, i);
		if (str[i] == '$' && str[i + 1] == '?')
			i += ft_question_handler(&tmp0);
		else if (str[i] == '$' && (str[i + 1] != '"'
				|| str[i + 2]) && str[i + 1] != ' ')
			i += ft_translator(i, str, &tmp0, data);
		else
		{
			tmp1 = ft_converter(str[i++], data);
			tmp2 = ft_strjoin(tmp0, tmp1);
			free (tmp0);
			tmp0 = tmp2;
			free (tmp1);
		}
	}
	return (tmp0);
}

char	**ft_quote_handler(char **str, int i, int r)
{
	if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1))
	{
		if (r)
			str[i] = ft_rm_quote(str[i], '\"');
		str[i] = ft_rm_quote(str[i], '\'');
	}
	return (str);
}

char	**ft_expander(t_data *data, char **cmd)
{
	char	*str;
	int		i;
	int		r;

	i = 0;
	r = 1;
	while (cmd[i])
	{
		if (ft_dollar_s(cmd[i]) //&& cmd[i][ft_dollar_s(cmd[i]) - 2] != '\''
				&& cmd[i][ft_dollar_s(cmd[i])] && cmd[i][0] != '\'')
		{
			str = ft_gold_finder(data, cmd[i]);
			if (!i && !str[0] && !cmd[i + 1])
				ft_shell_reset(data);
			free(cmd[i]);
			cmd[i] = str;
			if (cmd[i] && cmd[i][0] == '\'')
				r = 0;
		}
		if (cmd[i][0] == '\'')
			r = 0;
		cmd = ft_quote_handler(cmd, i, r);
		i++;
	}
	return (ft_skipper(cmd));
}
