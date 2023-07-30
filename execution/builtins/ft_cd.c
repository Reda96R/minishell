/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:33 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/30 13:13:56 by YOUNES           ###   ########.fr       */
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
		if (!strcmp(var->key, "PWD"))
		{
			free(var->value);
			pwd = getcwd(NULL, 0);
			if (!pwd)
				var->value = ft_strdup(g_var.data->pwd);
			else
				var->value = pwd;
		}
		var = var->next;
	}
}

void	change_oldpwd(char *old_pwd)
{
	t_vars	*var;

	var = g_var.data->vars;
	while (var)
	{
		if (!strcmp(var->key, "OLDPWD"))
		{
			free(var->value);
			var->value = old_pwd;
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
	return (1);
}

char	*get_home(t_data *data)
{
	char	*home;
	t_vars	*var;
	
	home = malloc(sizeof(char *));
	var = data->vars;
	while (var)
	{
		if (!strcmp(var->key, "HOME"))
		{
			home = var->value;
			return (home);
		}
		var = var->next;
	}
	return NULL;
}

int	ft_cd(t_cmds *init)
{
	char	*HOME;

	HOME = get_home(g_var.data);
	if (!init->str[1] || !strcmp(init->str[1], "~"))
	{
		if (!chdir(HOME))
			return (change_oldpwd(g_var.data->pwd), change_pwd(), 0);
		return (ft_builtins_error(2, NULL), 0);
	}
	if (strcmp(init->str[1], "."))
	{
		if (!chdir(init->str[1]))
		{	
			change_oldpwd(g_var.data->pwd);
			change_pwd();
		}
		else
			return (ft_builtins_error(2, init->str[1]), 0);
	}
	check_fail();
	return (0);
}
