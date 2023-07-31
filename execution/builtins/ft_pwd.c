/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 17:19:25 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_cmds *init)
{
	char	*pwd;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		_dprintf(init->fd_out, "%s\n", g_var.data->pwd);
		return ;
	}
	_dprintf(init->fd_out, "%s\n", pwd);
	free(pwd);
}
