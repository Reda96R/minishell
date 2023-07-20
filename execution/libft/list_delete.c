/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:12:37 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/20 18:46:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*del(void *content)
{
	free(content);
	return (NULL);
}

void	lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->key);
	free(lst);
}

void	lstclear(t_env **lst, void (*del)(void *))
{
	t_env	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		lstdelone(*lst, del);
		*lst = tmp;
	}
}

