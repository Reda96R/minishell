/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_vars_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:28:33 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 01:57:19 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_paths_parser(t_data *data)
{
	char	*path;
	char	*str;
	char	*last_char;
	int		i;

	i = 0;
	path = ft_path_finder(data->vars);
	if (!path)
		ft_errors_buster(4, data);
	data->paths = ft_split(path, ':');
	free(path);
	while (data->paths[i])
	{
		last_char = &data->paths[i][ft_strlen(data->paths[i]) - 1];
		if (ft_strncmp(last_char, "/", 1))
		{
			str = ft_strdup(data->paths[i]);
			free (data->paths[i]);
			data->paths[i] = ft_strjoin(str, "/");
			free(str);
		}
		i++;
	}
}

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
	(*new_n)->key = ft_substr(str, 0, i);
	(*new_n)->value = ft_substr(str, i + 1, ft_strlen(str) - i);
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
