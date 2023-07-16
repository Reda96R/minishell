/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:56:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/25 15:03:25 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_env	*dup_env(char **str)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		lst_add_back(&tmp, lstnew(ft_strdup(str[i])));
		i++;
	}
	return (tmp);
}

void	ft_init(t_init *init, char **env)
{
	init->t_env = dup_env(env);
}
