/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_scanner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:38:46 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 08:54:38 by rerayyad         ###   ########.fr       */
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
	if (id == PIPE && data->mylexer->next)
		if (data->mylexer->next->token_id == PIPE)
			ft_errors_buster(3, data);
	if (!ft_new_node(&new, id, NULL, 0) || !new)
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
	char	*tmp;

	new = NULL;
	j = 0;
	r = 0;
	while (data->input[i + j])
	{
		if ((data->input[i + j] == '\'' || data->input[i + j] == '\"') && !r)
			j = ft_true_word(data, i, r, j);
		else
			if (ft_check(data, i, &j, r))
				break ;
	}
	tmp = ft_substr(data->input, i, j);
	if (!ft_new_node(&new, 0, tmp, 0) || !new)
		return (-1);
	if (tmp)
		free (tmp);
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
