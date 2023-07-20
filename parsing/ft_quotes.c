/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:18:09 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/20 18:45:36 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quote_skiper(char *str, int quote, int i)
{
	int	j;

	j = 0;
	if (str[i + j] == quote)
	{
		while (str[i + j] && str[i + j] != quote)
			j++;
		j++;
	}
	return (j);
}

int	ft_quotes_matcher(char *input, int i, int quote, int *quote_count)
{
	int	j;

	j = i + 1;
	*quote_count += 1;
	while (input[j] && input[j] != quote)
		j++;
	if (input[j] == quote)
		*quote_count += 1;
	return (j - i);
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
			i += ft_quotes_matcher(input, i, '\'', &single_quotes);
		if (input[i] == '\"')
			i += ft_quotes_matcher(input, i, '\"', &double_quotes);
		i++;
	}
	return ((single_quotes % 2 == 0) && (double_quotes % 2 == 0));
}
