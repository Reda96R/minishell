/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:53 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/08 10:29:16 by rerayyad         ###   ########.fr       */
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
		{
		// printf("%c\n", cmd[i][j]);
			j++;
		}
		i++;
	}
	str = (char **) malloc(sizeof (char *) * j + 1);
	if (!str)
		ft_errors_buster(4, g_var.data);
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (*cmd[i])
			str[j++] = cmd[i];
		i++;
	}
	str[j] = NULL;
	// exit (0);
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
		else if (str[i] == '$' && ft_isalnum(str[i + 1]) && str[i + 1] != ' ')
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
	// exit (0);
	return (tmp0);
}

char	*ft_quote_handler(char *cmd, int *j)
{
	char	r;

	r = cmd[*j];
	if (r == '\'')
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
	}
	else
	{
		// printf("check\n");
		*j += 1;
		// printf("%d\n", *j);
		// printf("%c\n", cmd[*j + 1]);
		if (ft_dollar_s(ft_substr(cmd, *j, ft_strlen(cmd))) && cmd[*j] != r)
		{
			while (cmd[*j] && cmd[*j] != r)
			{
				if (cmd[*j] == '$')
				{
					if (cmd[*j + 1] == '\"' || cmd[*j + 1] == '\'' || !ft_isalnum(cmd[*j + 1]))
					{
						cmd[*j] = -3;
						*j += 1;
					}
					else if (cmd[*j + 1] != '\'' && cmd[*j + 1] != '\"' && cmd[*j + 1] != '$')
					{
						cmd = ft_gold_finder(g_var.data, cmd);
					}
				}
				else
				{
					if (cmd[*j] == '\'')
						cmd[*j] = -1;
					*j += 1;
				}
			}
		}
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
	// exit (0);
	return (cmd);
}

char	*ft_black_box(char *str)
{
	int	i;

	i = 0;
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

char	**ft_expander(t_data *data, char **cmd)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == '\'' || cmd[i][j] == '\"')
			{
				// printf("------------------first------------------\n");
				cmd[i] = ft_quote_handler(cmd[i], &j);
				// printf("%c\n", cmd[i][j]);
			}
			else if (cmd[i][j] == '$' && cmd[i][j + 1] != '\'' && cmd[i][j + 1] != '\"')
			{
				// printf("------------------second-----------------\n");
				// printf("%c\n", cmd[i][j]);
				if (!ft_isalnum(cmd[i][j + 1]) && cmd[i][j + 1] != '?')
					cmd[i][j++] = -3;
				else
				{
					str = ft_gold_finder(data, cmd[i]);
					if (!i && !str[0] && !cmd[i + 1])
						ft_shell_reset(data);
					free(cmd[i]);
					cmd[i] = str;
					if (cmd[i][j] != '\'' && cmd[i][j] != '\"')
						j++;
				}
			}
			else
			{
				// printf("----------------third-------------------\n");
				// printf("%c\n", cmd[i][j]);
				j++;
			}
			// if (ft_strncmp(cmd[0], "export", ft_strlen(cmd[0]) - 1))
			// {
			// 	cmd[i] = ft_rm_quote(cmd[i], '\"', 1);
			// 	cmd[i] = ft_rm_quote(cmd[i], '\'', 1);
			// }
		}
		ft_rm_quote(cmd[i], '\'', 1);
		ft_rm_quote(cmd[i], '\"', 1);
		ft_rm_quote(cmd[i], '$', 1);
		ft_black_box(cmd[i]);
		i++;
	}
	// printf("%s\n", cmd[1]);
	// exit (0);
	// printf("%s\n", cmd[1]);
	// exit (0);
	return (ft_skipper(cmd));
}
