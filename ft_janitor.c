/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/06 15:58:11 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// void  ft_data_prep(t_data *data)
// {
//   data->mylexer = NULL;
//   data->cmds = NULL;
//   data->mylexer = NULL;
//   ft_env_setter(data, data->vars, 0);
// }

void  ft_errors_buster(int id, t_data *data)
{
  printf("\033[0;31m");
	if (id == 1)
	{
		printf("ERROR: run without argument\n");
		exit (0);
	}
	else if (id == 2)
		printf("ERROR: unmatched quotes\n");
	else if (id == 3)
		printf("syntax error near unexpected token\n");
	else if (id == 4)
		printf("memory error: unable to allocate memory\n");
	data->color = 0;
	ft_shell_reset(data);
}

void  ft_lxr_cleaner(t_mylxr **mylexer)
{
  t_mylxr *tmp;

  if (!mylexer)
    return ;
  while (*mylexer)
  {
    tmp = (*mylexer)->next;
    if ((*mylexer)->str)
      free((*mylexer)->str);
    free(*mylexer);
    *mylexer = tmp;
  }
  *mylexer = NULL;
}

void  ft_cmd_cleaner(t_cmds **cmds)
{
  t_mylxr *redirections;
  t_cmds  *tmp;

  if (!cmds)
    return ;
  while (*cmds)
  {
    tmp = (*cmds)->next;
    redirections = (*cmds)->redirections;
    ft_lxr_cleaner(&redirections);
	// if ((*cmds)->str)
	// 		ft_arr_free((*cmds)->str);
    free(*cmds);
    *cmds = tmp;
  }
  *cmds = NULL;
}

t_mylxr	*ft_node_clear(t_mylxr **node)
{
	if ((*node)->str)
	{
		free((*node)->str);
		(*node)->str = NULL;
	}
	free(*node);
	*node = NULL;
	return (NULL);
}
