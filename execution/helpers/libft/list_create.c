/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:10:53 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/20 18:46:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*lstnew(void *key)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->next = NULL;
	return (new);
}

t_env	*lstlast(t_env *lst)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	lst_add_back(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (new)
	{
		if (*lst)
		{
			tmp = lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}
