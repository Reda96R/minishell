/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/20 18:46:03 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_remover(char **vars, char **rslt, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars[i])
	{
		if ()
		{
			rslt[j] = ft_strdup(vars[i]);
			if (!rslt[j])
			{
				ft_arr_free(rslt);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (rslt);
}

char	**ft_rm_var(t_data *data, char *str)
{
	char	**rslt;
	size_t	n;

	n = 0;
	while (data->vars[n])
		n++;
	rslt = (char **) malloc(sizeof (char *) * n + 1);
	if (!rslt)
		ft_errors_buster(4, data);
	rslt = ft_remover(data->vars, rslt, str);
	if (!rslt)
		ft_errors_buster(4, data);
	return (rslt);
}
void	ft_unset_check(t_cmds *cmds, t_data *data)
{
	int	i;

	i = 0;
	if (!cmds->str[1])
		ft_errors_buster(5, data);
	while (cmds->str[1][i])
	{
		if (cmds->str[1][i++] == '/')
		{
			ft_putstr_fd("ERROR: unset: `", STDERR_FILENO);
			ft_putstr_fd(cmds->str[1], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier", STDERR_FILENO);
			ft_shell_reset(data);
		}
	}
	if (!ft_strncmp(cmds->str[1], "=", 1))
	{
		ft_putendl_fd("ERROR: unset: not a valid identifier", STDERR_FILENO);
		ft_shell_reset(data);
	}
}

void	ft_unset(t_data *data, t_cmds *cmds)
{
	char	**str;

	ft_unset_check(cmds, data);
	str = ft_rm_var(data, cmds->str[1]);
	ft_arr_free(data->vars);
	data->vars = str;
}
