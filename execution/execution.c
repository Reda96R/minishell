/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:47:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/20 18:46:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_init	*init;
	char	*line;

	init = malloc(sizeof(t_init));
	ft_init(init, env);
	while (1)
	{
		signals();
		line = readline("\033[0;32m<?>\033[0m ");
		if (!line)
			return (printf("exit\n"), exit(0), 0);
		if (strcmp(line, "exit") == 0)
			exit(0);
	}
	return (0);
}
