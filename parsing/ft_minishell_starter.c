/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_starter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:09:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/23 11:24:31 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_shell_reset(t_data *data)
{
	if (data->input)
		free(data->input);
	ft_cmd_cleaner(&data->cmds);
	ft_shell_starter(data);
}

void	ft_prompt(t_data *data)
{
	if (!data->color)
		data->input = ft_strtrim(readline(READLINE_MSG_R), " ");
	else
		data->input = ft_strtrim(readline(READLINE_MSG_G), " ");
	if (!data->input)
	{
		printf("exit\n");
		exit(0);
	}
	if (data->input[0])
		add_history(data->input);
}
// void ft_check(t_data *init)
// {
// 
// }

void	ft_shell_starter(t_data *data)
{
	while (1)
	{
		ft_env_var(data, NULL, 0);
		signals();
		ft_prompt(data);
		if (ft_quotes_counter(data->input))
		{
			data->color = 1;
			if (ft_token_scanner(data) > 0)
			{
				data->color = 1;
				ft_parser(data);
				// ft_check(data);
				// exit (0);
				ft_execution(data);
				ft_shell_reset(data);
			}
			else if (ft_token_scanner(data) == -1)
				ft_errors_buster(3, data);
		}
		else
			ft_errors_buster(2, data);
	}
}
