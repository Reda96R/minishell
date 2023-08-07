/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:32:30 by YOUNES            #+#    #+#             */
/*   Updated: 2023/08/07 17:21:24 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(t_mylxr *del)
{
	int	pp[2];
	char *str;

	pipe(pp);
	while (1)
	{
		str = readline("> ");
		if (!str || !_strcmp(del->str, str))
			break ;
		_dprintf(pp[1], "%s\n", str);
		free(str);
	}
	signals();
	return (pp[0]);
}
