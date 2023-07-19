/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lxr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 06:38:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/19 06:38:04 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_new_node(t_mylxr **new ,int id, char *str)
{
	*new = (t_mylxr *) malloc(sizeof (t_mylxr));
	if (!new)
		return (0);
	(*new)->token_id = id;
	(*new)->str = str;
	(*new)->next = NULL;
	(*new)->prev = NULL;
	return (1);
}

void  ft_add_node(t_mylxr **mylxr, t_mylxr *new)
{
	t_mylxr *tmp;

	tmp = *mylxr;
	if (!new->node_id)
	{
		*mylxr = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void  ft_rm_node(t_mylxr **mylexer, int id)
{
	t_mylxr *node;
	t_mylxr *prev;

	node = *mylexer;
	prev = NULL;
	while (node)
	{
		if (node->node_id == id)
		{
			if (prev)
				prev->next = node->next;
			else
				*mylexer = node->next;
			if (node->next)
				node->next->prev = prev;
			ft_node_clear(&node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}

