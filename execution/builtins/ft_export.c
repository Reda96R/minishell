/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/07 11:55:47 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_export(char *str)
{
	int	i;
	
	i = 0;
	if (!_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+' && str[i + 1] == '=')
		{
			i++;
			continue ;
		}
		if (!_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

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
void	new_var(char **str)
{
	t_vars *prev;
	t_vars *node;
	int		id;
	
	id = 0;
	prev = g_var.data->vars;
	while (prev->next)
	{
		id++;	
		prev = prev->next;
	}
	id++;
	node = malloc(sizeof(t_vars));
	if (!node)
		ft_error_exec(8, NULL, 0);
	node->key = str[0];
	node->value = str[1];
	node->node_id = id;
	node->next = NULL;
	node->prev = prev;
	prev->next = node;
}

char **get_keyvalue(char *ident, int *i)
{
	char **str;
	int	j;

	str = malloc(2 * sizeof(char *));
	j = 0;
	while (ident[j] && ident[j] != '=')
	{
		if (ident[j] == '+' && ident[j + 1] == '=')
			break ;
		j++;
	}
	str[0] = ft_substr(ident, 0, j);
	if (ident[j] == '+')
		str[1] = ft_substr(ident, j + 2, ft_strlen(&ident[j + 1]));
	else if (ident[j] == '=')
		str[1] = ft_substr(ident, j + 1, ft_strlen(&ident[j]));
	if (ident[j] != '=' && ident[j] != '+')
		str[1] = NULL;
	*i = j;
	return (str);
}

void	add_var(char *ident)
{
	t_vars *tmp;
	char **str;
	int	j;

	str = get_keyvalue(ident, &j);
	tmp = g_var.data->vars;
	while (tmp)
	{
		if (!_strcmp(tmp->key, str[0]))
		{
			if (str[1])
			{
				if (ident[j] == '+')
					tmp->value = _strjoin(tmp->value, str[1]);
				else
					tmp->value = str[1];
			}
			return;
		}
		tmp = tmp->next;
	}
	new_var(str);
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
		if (ft_check_export(init->str[i]))
			add_var(init->str[i]);
		else
			ft_builtins_error(8, init->str[i]);
		i++;
    }
}
