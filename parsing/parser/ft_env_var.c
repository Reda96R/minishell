/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:07:32 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/16 12:45:11 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_path_finder(t_vars *vars)
{
	char	*path;

	path = NULL;
	while (vars)
	{
		if (vars->key && !_strcmp(vars->key, "PATH"))
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
		if (tmp->key && !_strcmp(tmp->key, "PWD"))
		{
			if (tmp->value)
			{
				free(data->pwd);
				data->pwd = ft_strdup(tmp->value);
			}
		}
		if (tmp->key && !_strcmp(tmp->key, "OLDPWD"))
		{
			if (tmp->value)
			{
				free(data->old_pwd);
				data->old_pwd = ft_strdup(tmp->value);
			}
		}
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
	int		i;

	if (n && *env)
		if (!ft_env_setter(data, env, n))
			return (0);
	tmp = data->vars;
	if (!tmp)
		return (1);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	data->env = (char **) malloc(sizeof (char *) * (i + 1));
	if (!data->env)
		ft_errors_buster(4, data);
	ft_paths_parser(data);
	ft_pwd_finder(data->vars, data);
	ft_fill_env(data);
	return (1);
}
