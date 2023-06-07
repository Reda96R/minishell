/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:18:09 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/07 12:18:10 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_quotes_matcher(char *input, int i, int quote)
{
  int j;
  int quote_count;

  // (void)i;
  j = ++i;
  quote_count = 1;
  while (input[j] /*&& input[j] != quote*/)
  {
    if (input[j] == quote)
      quote_count++;
    j++;
  }
  if (input[j] == quote)
    quote_count++;
  return (quote_count);
}

int ft_quotes_counter(char *input)
{
  int single_quotes;
  int double_quotes;
  int i;

  i = 0;
  single_quotes = 0;
  double_quotes = 0;
  while (input[i])
  {
    if (input[i] == '\'')
      single_quotes += ft_quotes_matcher(input, i, '\'');
    else if (input[i] == '\"')
      double_quotes += ft_quotes_matcher(input, i, '\"');
    i++;
  }
  return (single_quotes % 2 == 0) && (double_quotes % 2 == 0);
}

