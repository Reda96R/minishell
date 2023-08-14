/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:28:18 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/14 19:27:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_free(char **arr);
void	ft_add(t_vars *tmp, char id, char **str);

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

void	_print(t_cmds *init)
{
	t_vars	*tmp;

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
	t_vars	*prev;
	t_vars	*node;
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
	if (str[0])
		node->key = _strdup(str[0]);
	node->value = NULL;
	if (str[1])
		node->value = _strdup(str[1]);
	node->node_id = id;
	node->next = NULL;
	node->prev = prev;
	prev->next = node;
}

char	**get_keyvalue(const char *ident, int *i)
{
	char	**str;
	int		j;

	str = malloc(2 * sizeof(char *));
	if (!str)
		ft_errors_buster(4, g_var.data);
	j = 0;
	while (ident[j] && ident[j] != '=')
	{
		if (ident[j] == '+' && ident[j + 1] == '=')
			break ;
		j++;
	}
	str[0] = _substr(ident, 0, j);
	if (ident[j] == '+')
		str[1] = _substr(ident, j + 2, _strlen(&ident[j + 1]));
	else if (ident[j] == '=')
		str[1] = _substr(ident, j + 1, _strlen(&ident[j]));
	if (ident[j] != '=' && ident[j] != '+')
		str[1] = NULL;
	*i = j;
	return (str);
}

void	add_var(const char *ident)
{
	t_vars	*tmp;
	char	**str;
	int		j;

	str = get_keyvalue(ident, &j);
	tmp = g_var.data->vars;
	while (tmp)
	{
		if (!_strcmp(tmp->key, str[0]))
		{
			if (str[1])
				ft_add(tmp, ident[j], str);
			_free(str);
			return ;
		}
		tmp = tmp->next;
	}
	new_var(str);
	_free(str);
}
