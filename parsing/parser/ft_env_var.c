/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:07:32 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/12 15:17:00 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_path_finder(t_vars *vars)
{
	char	*path;

	path = NULL;
	while (vars)
	{
		if (!ft_strncmp(vars->key, "PATH", 4))
		{
			path = ft_substr(vars->value, 0, ft_strlen(vars->value));
			break ;
		}
		vars = vars->next;
	}
	if (!path)
		path = ft_strdup("");
	return (path);
}

void	ft_pwd_finder(t_vars *vars, t_data *data)
{
	t_vars	*tmp;

	tmp = vars;
	while (tmp)
	{
		if (!ft_strncmp((const char *)tmp->key, "PWD", 3))
			if (tmp->value)
				data->pwd = ft_strdup(tmp->value);
		if (!ft_strncmp(tmp->key, "OLDPWD", 6))
			if (tmp->value)
				data->old_pwd = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
}

int	ft_env_setter(t_data *data, char **env, int n)
{
	int		i;
	t_vars	*new;
	int		node_id;

	if (n)
	{
		i = 0;
		node_id = 0;
		while (env[i])
		{
			if (!ft_new_var(&new, node_id, env[i++]))
				return (0);
			node_id++;
			ft_add_var(&data->vars, new);
		}
	}
	return (1);
}

void	ft_fill_env(t_data *data)
{
	t_vars	*tmp;
	char	*str;
	int		i;

	tmp = data->vars;
	i = 0;
	while (tmp)
	{
		if (tmp->value)
		{
			str = ft_strjoin(tmp->key, "=");
			data->env[i] = ft_strjoin(str, tmp->value);
			free(str);
			i++;
		}
		tmp = tmp->next;
	}
	data->env[i] = NULL;
}

int	ft_env_var(t_data *data, char **env, int n)
{
	t_vars	*tmp;

	if (n)
	{
		if (!ft_env_setter(data, env, n))
			return (0);
	}
	tmp = data->vars;
	if (!tmp)
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	data->env = (char **) malloc(sizeof (char *) * (tmp->node_id + 2));
	if (!data->env)
		return (0);
	ft_paths_parser(data);
	ft_pwd_finder(data->vars, data);
	ft_fill_env(data);
	return (1);
}
