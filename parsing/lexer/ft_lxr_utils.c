/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lxr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:38:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 05:51:01 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_new_node(t_mylxr **new, int id, char *str, int n)
{
	*new = (t_mylxr *) malloc(sizeof (t_mylxr));
	if (!new)
		ft_errors_buster(4, g_var.data);
	if (n)
		if (!str)
			ft_errors_buster(6, g_var.data);
	(*new)->token_id = id;
	(*new)->str = ft_strdup(str);
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

void	ft_add_node(t_mylxr **mylxr, t_mylxr *new)
{
	t_mylxr	*tmp;

	if (!new->node_id)
	{
		*mylxr = new;
		return ;
	}
	tmp = *mylxr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_rm_node(t_mylxr **mylexer, int id)
{
	t_mylxr	*node;
	t_mylxr	*prev;

	node = *mylexer;
	prev = NULL;
	while (node)
	{
		if (node->node_id == id)
		{
			if (prev)
				prev->next = node->next;
			else
			{
				*mylexer = node->next;
				if ((*mylexer))
					(*mylexer)->prev = NULL;
			}
			if (prev && node->next)
				node->next->prev = prev;
			ft_node_clear(&node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

int	ft_pipe_identifier(t_data *data, int i)
{
	if (ft_token_identifier(data, i + 1) != PIPE && data->input[i + 1]
		&& data->mylexer->token_id != PIPE)
	{
		data->pipes++;
		return (PIPE);
	}
	return (-1);
}

int	ft_redirection_identifier(t_data *data, int i)
{
	if (data->input[i] == '>')
	{
		if (data->input[i + 1] == '>' && !ft_token_identifier(data, i + 2))
			return (D_GREATER);
		else if (!ft_token_identifier(data, i + 1))
			return (GREATER);
		return (-1);
	}
	else
	{
		if (data->input[i + 1] == '<' && !ft_token_identifier(data, i + 2))
			return (D_LESS);
		else if (!ft_token_identifier(data, i + 1))
			return (LESS);
		return (-1);
	}
}
