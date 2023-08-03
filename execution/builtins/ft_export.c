/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/03 17:52:15 by yes-slim         ###   ########.fr       */
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
    int i;

    i = 1;
    if (!init->str[i])
        _print();
    while (init->str[i])
    {
        printf("%s\n", init->str[i]);
        i++;
    }
}