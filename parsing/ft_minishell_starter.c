/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_starter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:09:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/19 11:52:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

void  ft_shell_reset(t_data *data)
{
  // if (data->input)
	free(data->input);
	ft_cmd_cleaner(&data->cmds);
	ft_shell_starter(data);
}

void  ft_prompt(t_data *data)
{
  if (!data->color)
    data->input = ft_strtrim(readline(READLINE_MSG_R), " ");
  else
    data->input = ft_strtrim(readline(READLINE_MSG_G), " ");
  if (!data->input)
    exit(0);
  if (data->input[0])
    add_history(data->input);
}

void ft_check(t_data *data)
{
	t_cmds *tmp;
	tmp = data->cmds;
	int i = 0;
	while (tmp)
	{
		while (tmp->str[i])
			printf("cmd: %s ", tmp->str[i++]);
		printf("\n");
		tmp = tmp->next;
	}
}

void  ft_shell_starter(t_data *data)
{
	while (1)
	{
		ft_prompt(data);
		if (ft_quotes_counter(data->input))
		{
			data->color = 1;
			if (ft_token_scanner(data) > 0)
			{
				data->color = 1;
				ft_parser(data);
				ft_check(data);
				ft_shell_reset(data);
			}
			else if (ft_token_scanner(data) == -1)
				ft_errors_buster(3, data);
		}
		else
			ft_errors_buster(2, data);
    // free(data->input);
  }
}
//
//     if (tools->args[0] == '\0')
//     {
//       free(tools->args);
//       return (ft_reset(tools));
//     }
//       if (ft_quotes_counter(tools->args))
//       {
//         if (ft_token_reader(tools))
//           {
//             ft_parser(tools);
//             ft_exec_prep(tools);
//             ft_reset(tools);
//           }
//         else
//           ft_error_busters(3, tools);
//       }
//       else 
//         ft_error_busters(4, tools);
//       free(tools->args);
//     }
//     return (ft_reset(tools));
// }
//

