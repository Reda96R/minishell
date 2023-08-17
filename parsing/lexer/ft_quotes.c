/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:18:09 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 08:54:45 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_check(t_data *data, int i, int *j, int r)
{
	if ((ft_token_identifier(data, (*j + i))
			|| ft_isspace(data->input[*j + i])) && !r)
		return (1);
	*j += 1;
	return (0);
}

char	*ft_rm_quote(char *str, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			ft_strlcpy(&str[i], &str[i + j], ft_strlen(str) - i);
			if (!n)
				return (str);
		}
		i++;
	}
	return (str);
}

int	ft_quote_skiper(char *str, int quote, int i)
{
	if (str[i] == quote)
	{
		i++;
		while (str[i] && str[i] != quote)
			i++;
		i++;
	}
	return (i);
}

int	ft_quotes_matcher(char *input, int i, int quote, int *quote_count)
{
	int	j;

	*quote_count += 1;
	j = i + 1;
	while (input[j] && input[j] != quote)
		j++;
	if (input[j] == quote)
	{
		*quote_count += 1;
		j++;
	}
	return (j);
}

int	ft_quotes_counter(char *input)
{
	int	single_quotes;
	int	double_quotes;
	int	i;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			i = ft_quotes_matcher(input, i, '\'', &single_quotes);
		else if (input[i] == '\"')
			i = ft_quotes_matcher(input, i, '\"', &double_quotes);
		else if (input[i] && input[i] != '\'' && input[i] != '\"')
			i++;
	}
	return ((single_quotes % 2 == 0) && (double_quotes % 2 == 0));
}
