/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:33 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/15 23:31:20 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(void);
void	change_oldpwd(char *old_pwd);
int		check_fail(void);
char	*get_home(t_data *data);
void	ft_cdhome(void);

int	ft_cd(t_cmds *init)
{
	int	i;

	i = 0;
	while (init->str[i])
		i++;
	if (i > 2)
		return (ft_builtins_error(10, NULL), 0);
	if (!init->str[1] || !_strcmp(init->str[1], "~"))
		ft_cdhome();
	if (init->str[1])
	{
		if (_strcmp(init->str[1], "."))
		{
			if (!chdir(init->str[1]))
			{	
				change_pwd();
				change_oldpwd(g_var.data->pwd);
			}
			else
				return (ft_builtins_error(3, init->str[1]), 0);
		}
		check_fail();
	}
	return (g_var.exit_status = 0, 0);
}
