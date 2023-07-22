/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:07:32 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/22 21:46:14 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_path_finder(t_vars *vars)
{
	char	*path;

	path = NULL;
	while (vars)
	{
		if (!ft_strncmp(vars->key, "PATH=", 5))
		{
			path = ft_substr(vars->value, 5, ft_strlen(vars->value) - 5);
			break ;
		}
		vars = vars->next;
	}
	if (!path)
		path = ft_strdup("");
	return (path);
}

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
			str = ft_strjoin(data->paths[i], "/");
			data->paths[i] = str;
		}
		i++;
	}
}

void	ft_pwd_finder(t_vars *vars, t_data *data)
{
	t_vars	*tmp;

	tmp = vars;
	while (tmp)
	{
		if (!ft_strncmp((const char *)tmp->key, "PWD", 3))
			data->pwd = ft_strdup(tmp->value);
		else if (!ft_strncmp(tmp->key, "OLDPWD", 6))
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
		ft_pwd_finder(data->vars, data);
	}
	ft_paths_parser(data);
	return (1);
}

int	ft_env_var(t_data *data, char **env, int n)
{
	int		i;
	char	*str;
	t_vars	*tmp;

	if (!ft_env_setter(data, env, n))
		return (0);
	tmp = data->vars;
	while (tmp->next)
		tmp = tmp->next;
	data->env = (char **) malloc(sizeof (char *) * (tmp->node_id + 2));
	if (!data->env)
		return (0);
	tmp = data->vars;
	i = 0;
	while (tmp)
	{
		if (tmp->value)
		{
			str = ft_strjoin(tmp->key, "=");
			data->env[i] = ft_strdup(ft_strjoin(str, tmp->value));
			free (str);
			i++;
		}
		tmp = tmp->next;
	}
	data->env[i] = NULL;
	return (1);
}
