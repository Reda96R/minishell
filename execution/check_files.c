/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:59:29 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/30 15:24:47 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_check_infile(t_cmds *cmd)
{
	t_mylxr	*start;

	start = cmd->redirections;
	while (cmd->redirections)
	{
		// printf("test\n");
		printf("%s\n", cmd->redirections->str);
		// if (!cmd->redirections->str)
		cmd->redirections = cmd->redirections->next;
		// printf("here\n");
	}
}
