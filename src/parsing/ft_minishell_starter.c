/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_starter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:09:50 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/06 17:09:52 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void  ft_shell_starter(t_data *data)
{
  // char  *str;

  while (1)
  {
    if (data->color)
      data->input = ft_strtrim(readline(READLINE_MSG_G), " ");
    else
      data->input = ft_strtrim(readline(READLINE_MSG_R), " ");
    if (!data->input)
    {
      printf("exit\n");
      exit(0);
    }
    add_history(data->input);
    if (ft_quotes_counter(data->input))
    {
        // if (ft_token_reader(data))
        // {
        // }
        // else
          // ft_error_busters(3);
        data->color = 1;
    }
    else
      ft_errors_buster(2, data);
  }
  free(data->input);
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

