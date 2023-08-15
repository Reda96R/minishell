/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:28:10 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 23:28:52 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(void)
{
	t_vars	*var;
	char	*pwd;

	var = g_var.data->vars;
	while (var)
	{
		if (!_strcmp(var->key, "PWD"))
		{
			free(var->value);
			pwd = getcwd(NULL, 0);
			if (!pwd)
				var->value = _strdup(g_var.data->pwd);
			else
			{
				var->value = _strdup(pwd);
				free(pwd);
			}
		}
		var = var->next;
	}
}

void	change_oldpwd(char *old_pwd)
{
	t_vars	*var;

	if (!old_pwd)
		return ;
	var = g_var.data->vars;
	while (var)
	{
		if (!_strcmp(var->key, "OLDPWD"))
		{
			free(var->value);
			var->value = _strdup(old_pwd);
		}
		var = var->next;
	}
}

int	check_fail(void)
{
	char	*check;

	check = getcwd(NULL, 0);
	if (!check)
	{
		free(check);
		ft_builtins_error(1, NULL);
		return (0);
	}
	free(check);
	return (1);
}

char	*get_home(t_data *data)
{
	char	*home;
	t_vars	*var;

	var = data->vars;
	while (var)
	{
		if (!_strcmp(var->key, "HOME"))
		{
			home = _strdup(var->value);
			return (home);
		}
		var = var->next;
	}
	return (NULL);
}

void	ft_cdhome(void)
{
	char	*home;

	home = get_home(g_var.data);
	if (!chdir(home))
	{
		free(home);
		g_var.exit_status = 0;
		change_oldpwd(g_var.data->pwd);
		change_pwd();
	}
	else
		ft_builtins_error(2, NULL);
}
