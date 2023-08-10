/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/09 14:16:38 by yes-slim         ###   ########.fr       */
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
