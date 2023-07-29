/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:59:29 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/29 11:36:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_infile(t_mylxr *files)
{
	while (files)
	{
		printf("%s---->%d\n", files->str, files->token_id);
		printf("%d\n", files->node_id);
		files = files->next;
	}
}
