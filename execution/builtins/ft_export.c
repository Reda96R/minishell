/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/04 11:35:46 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    _print(t_cmds *init)
{
    t_vars  *tmp;

    tmp = g_var.data->vars;
    while (tmp)
    {
        _dprintf(init->fd_out, "declare -x %s", tmp->key);
        if (tmp->value)
            _dprintf(init->fd_out, "=\"%s\"\n", tmp->value);
        tmp = tmp->next;
    }
}

void    ft_export(t_cmds *init)
{
    int		i;
    
	i = 1;
    if (!init->str[i])
        _print(init);
	while (init->str[i])
    {
		
		i++;
    }
}