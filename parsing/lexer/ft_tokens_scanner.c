/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_scanner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:38:46 by rerayyad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/08 14:12:29 by rerayyad         ###   ########.fr       */
=======
/*   Updated: 2023/08/08 14:21:41 by rerayyad         ###   ########.fr       */
>>>>>>> 0ba4d25ee0222ab8cccf930a629b6c9b4e1c1da9
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_token_identifier(t_data *data, int i)
{
	if (data->input[i] == '|')
		return (ft_pipe_identifier(data, i));
	else if (data->input[i] == '>' || data->input[i] == '<')
		return (ft_redirection_identifier(data, i));
	return (0);
}

int	ft_token_parser(t_data *data, int *node_id, int id)
{
	t_mylxr	*new;

	new = NULL;
	if (!ft_new_node(&new, id, NULL) || !new)
		return (-1);
	new->node_id = (*node_id)++;
	ft_add_node(&data->mylexer, new);
	if (id == 3 || id == 5)
		return (2);
	return (1);
}

int	ft_true_word(t_data *data, int i, int r, int j)
{
	r += ft_quote_skiper(data->input, '\"', i + j);
	r += ft_quote_skiper(data->input, '\'', i + j);
	if (r)
		j += r;
	while (data->input[i + j] && r)
	{
		if (data->input[i + j] == '\'' || data->input[i + j] == '\"')
			r = 0;
		j++;
	}
	return (j);
}

int	ft_words_parser(t_data *data, int *node_id, int i)
{
	t_mylxr	*new;
	int		j;
	int		r;

	new = NULL;
	j = 0;
	r = 0;
	while (data->input[i + j])
	{
		if ((data->input[i + j] == '\'' || data->input[i + j] == '\"') && !r)
			j = ft_true_word(data, i, r, j);
		else
		{
			if ((ft_token_identifier(data, i + j)
					|| ft_isspace(data->input[i + j])) && !r)
				break ;
			j++;
		}
	}
	if (!ft_new_node(&new, 0, ft_substr(data->input, i, j)) || !new)
		return (-1);
	new->node_id = (*node_id)++;
	ft_add_node(&data->mylexer, new);
	return (j);
}

int	ft_token_scanner(t_data *data)
{
	int	i;
	int	j;
	int	id;
	int	node_id;

	i = 0;
	j = 0;
	node_id = 0;
	data->pipes = 0;
	while (data->input[i])
	{
		while (data->input[i] && ft_isspace(data->input[i]))
			i++;
		id = ft_token_identifier(data, i);
		if ((id < 0 || (id == 1 && !node_id)))
			return (-1);
		if (id)
			j = ft_token_parser(data, &node_id, id);
		else
			j = ft_words_parser(data, &node_id, i);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
