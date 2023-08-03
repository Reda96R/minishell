/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/03 14:56:10 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    _print(void)
{
    t_vars  *tmp;

    tmp = g_var.data->vars;
    while (tmp)
    {
        printf("declare -x %s", tmp->key);
        if (tmp->value)
            printf("=\"%s\"\n", tmp->value);
        tmp = tmp->next;
    }
}

void    ft_export(t_cmds *init)
{
    if (init->str[1])
    {
        
    }
    else
        _print();
}