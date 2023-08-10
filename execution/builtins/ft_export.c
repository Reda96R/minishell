/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:41 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/10 21:29:32 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_export(char *str);
void	_print(t_cmds *init);
void	new_var(char **str);
char	**get_keyvalue(char *ident, int *i);
void	add_var(char *ident);

void	ft_export(t_cmds *init)
{
	int	i;

	i = 1;
	if (!init->str[1])
	{
		_print(init);
		return ;
	}
	while (init->str[i])
	{
		if (ft_check_export(init->str[i]))
			add_var(init->str[i]);
		else
			ft_builtins_error(8, init->str[i]);
		i++;
	}
}
