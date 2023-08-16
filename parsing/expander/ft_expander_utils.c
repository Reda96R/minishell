/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:31:04 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/16 00:38:59 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

char	*ft_converter(char *cmd, char c, t_data *data, int *i)
{
	char	*str;
	int		l;

	l = *i;
	if (c == '\'')
	{
		l++;
		while (cmd[l] && cmd[l] != '\'')
			l++;
		str = ft_substr(cmd, *i, l);
		*i = l;
		*i += 1;
		return (str);
	}
	str = (char *) malloc(sizeof (char) * 2);
	if (!str)
		ft_errors_buster(4, data);
	str[0] = c;
	str[1] = '\0';
	*i += 1;
	return (str);
}

int	ft_digit_skipper(char *str, int n)
{
	int	i;

	i = n;
	if (str[n] == '$')
		if (ft_isdigit(str[n + 1]))
			n += 2;
	return (n - i);
}

int	ft_question_handler(char **str)
{
	char	*tmp;
	char	*tmp0;

	tmp = ft_itoa((int)g_var.exit_status);
	tmp0 = ft_strjoin(*str, tmp);
	free (tmp);
	free (*str);
	*str = tmp0;
	return (2);
}

int	ft_lenght_cal(char *str, int i)
{
	int	j;

	j = i + 1;
	while (str[i] && (ft_isalnum(str[j]) || str[j] == '_'))
		j++;
	return (j);
}

int	ft_translator(int i, char *str, char **tmp, t_data *data)
{
	char	*tmp0;
	char	*tmp1;
	int		l;
	t_vars	*var;

	l = 0;
	var = data->vars;
	while (var)
	{
		if (!ft_strncmp(str + i + 1, var->key, ft_strlen(var->key))
			&& ft_lenght_cal(str, i) - i == (int)ft_strlen(var->key) + 1)
		{
			tmp0 = ft_strdup(var->value);
			tmp1 = ft_strjoin(*tmp, tmp0);
			free (*tmp);
			*tmp = tmp1;
			free (tmp0);
			l = ft_strlen(var->key) + 1;
		}
		var = var->next;
	}
	if (!l)
		l = ft_lenght_cal(str, i) - i;
	return (l);
}
