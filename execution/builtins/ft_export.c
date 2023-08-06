/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/06 10:14:18 by YOUNES           ###   ########.fr       */
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
            _dprintf(init->fd_out, "=\"%s\"", tmp->value);
		_dprintf(init->fd_out, "\n");
        tmp = tmp->next;
    }
}

int	ft_check(char *str)
{
	int	i;
	
	i = 0;
	if (!_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	add_var(char *ident)
{
	t_vars *prev;
	t_vars *tmp;
	t_vars *node;
	char *str[2];
	int	id;
	int	j;

	tmp = g_var.data->vars;
	id = 0;
	while(tmp)
	{
		id++;
		tmp = tmp->next;
	}
	prev = g_var.data->vars;
	while (prev->next)
		prev = prev->next;
	j = 0;
	while (ident[j] && ident[j] != '=')
		j++;
	str[0] = ft_substr(ident, 0, j);
	str[1] = ft_substr(ident, j + 1, ft_strlen(&ident[j]));
	if (ident[j] != '=')
		str[1] = NULL;
	tmp = g_var.data->vars;
	while (tmp)
	{
		if (!strcmp(tmp->key, str[0]))
		{
			if (str[1])
				tmp->value = str[1];
			return;
		}
		tmp = tmp->next;
	}
	node = malloc(sizeof(t_vars));
	if (!node)
		ft_error_exec(8, NULL);
	node->key = str[0];
	node->value = str[1];
	node->node_id = id;
	node->next = NULL;
	node->prev = prev;
	prev->next = node;
}

void    ft_export(t_cmds *init)
{
    int		i;
    
	i = 1;
    if (!init->str[1])
	{
		_print(init);
		return ;
	}
	while (init->str[i])
    {
		if (ft_check(init->str[i]))
			add_var(init->str[i]);
		else
			ft_builtins_error(8, init->str[i]);
		i++;
    }
}

void	del_var(char *str)
{
	t_vars	*tmp;

	tmp = g_var.data->vars;
	while (tmp)
	{
		if (!strcmp(tmp->key, str))
			tmp->prev->next = tmp->next; 
			// printf("%s\n", tmp->prev->key);
		tmp = tmp->next;
	}
}
void	ft_unset(t_cmds *init)
{
	int	i;

	i = 1;
	while(init->str[i])
	{
		if (ft_check(init->str[i]))
			del_var(init->str[i]);
		else
			ft_builtins_error(9, init->str[i]);
		i++;
	}
}