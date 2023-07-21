/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/21 20:50:18 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_data *init)
{
	char	*pwd;

	(void)init;
	pwd = getcwd(NULL, 0);
	// if (!pwd)
	// {
	// 	printf("%s\n", init->pwd);
	// 	return ;
	// }
	printf("%s\n", pwd);
	free(pwd);
}