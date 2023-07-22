/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/22 18:07:20 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/structs.h"

int	main(int ac, char *av[], char *env[])
{
	t_data	data;

	if (ac > 1 || av[1])
		ft_errors_buster(1, &data);
	if (!ft_env_var(&data, env, 1))
		return (0);
	data.color = 1;
	// int i = 0;
	// while (data.env[i])
	// 	printf("%s\n", data.env[i++]);
	// 	printf("%s\n", data.env[i++]);
	// printf("%s\n", data.env[39]);
	
	ft_shell_starter(&data);
	return (0);
}
