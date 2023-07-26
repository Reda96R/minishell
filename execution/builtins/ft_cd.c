/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:33 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/26 12:23:34 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(t_data *init, char *old_pwd)
{
	t_vars	*var;
	char	*pwd;
	
	var = init->vars;
	while (var)
	{
		if (!strcmp(var->key, "PWD"))
		{
			free(var->value);
			pwd = getcwd(NULL, 0);
			if (!pwd)
				var->value = ft_strdup(init->pwd);
			else
				var->value = pwd;
		}
		var = var->next;
	}
	var = init->vars;
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
		printf("cd: error retrieving current directory: getcwd: cannot ");
		printf("access parent directories: No such file or directory\n");
		return (0);
	}
	return (1);
}

char	*get_home(t_data *data)
{
	int		i;
	char	*home;
	t_vars	*var;

	i = 0;
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

	HOME = get_home(init->data);
	if (!init->str[1])
	{
		if (!chdir(HOME))
			return (change_dir(init->data, init->data->pwd), 0);
		return (printf("<?>: cd: HOME not set\n"), 0);
	}
	if (!chdir(init->str[1]))
		return (change_dir(init->data, init->data->pwd), 0);
	if (!strcmp(init->str[1], ".") || !strcmp(init->str[1], ".."))
	{
		if (!check_fail())
			change_dir(init->data, init->data->pwd);
		return (0);
	}
	return (printf("<?>: cd: %s: No such file or directory\n", init->str[1]), 0);
}
