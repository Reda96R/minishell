/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_vars_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:28:33 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/22 12:27:24 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <string.h>

t_vars	*ft_var_clear(t_vars **node)
{
	if ((*node)->key)
	{
		free ((*node)->key);
		(*node)->key = NULL;
	}
	if ((*node)->value)
	{
		free ((*node)->value);
		(*node)->value = NULL;
	}
	free (*node);
	*node = NULL;
	return (NULL);
}

int	ft_new_var(t_vars **new_n, int node_id, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	*new_n = (t_vars *) malloc(sizeof (t_vars));
	if (!new_n)
		return (0);
	(*new_n)->key = ft_strdup(ft_substr(str, 0, i));
	(*new_n)->value = ft_strdup(ft_substr(str, i + 1, ft_strlen(str) - i));
	(*new_n)->node_id = node_id;
	(*new_n)->next = NULL;
	(*new_n)->prev = NULL;
	return (1);
}

void	ft_add_var(t_vars **vars, t_vars *new_n)
{
	t_vars	*tmp;

	if (!new_n->node_id)
	{
		*vars = new_n;
		return ;
	}
	tmp = *vars;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_n;
	new_n->prev = tmp;
}

void	ft_rm_var(t_vars **vars, int id)
{
	t_vars	*node;
	t_vars	*prev;

	node = *vars;
	prev = NULL;
	while (node)
	{
		if (node->node_id == id)
		{
			if (prev)
				prev->next = node->next;
			else
			{
				*vars = node->next;
				if ((*vars))
					(*vars)->prev = NULL;
			}
			if (prev && node->next)
				node->next->prev = prev;
			ft_var_clear(&node);
			return ;
		}
		prev = node;
		node = node->next;
	}
}
