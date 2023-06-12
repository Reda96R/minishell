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

void  ft_data_prep(t_data *data)
{
  data->mylexer = NULL;
  data->cmds = NULL;
  data->mylexer = NULL;
  ft_env_setter(data, data->vars, 0);
}

void  ft_errors_buster(int id, t_data *data)
{
  if (id == 1)
    printf("ERROR: run without argument\n");
  else if (id == 2)
      printf("ERROR: unmatched quotes\n");
  else if (id == 3)
    printf("syntax error near unexpected token\n");
  else if (id == 4)
    printf("memory error: unable to allocate memory\n");
  // ft_cleaner(data);
  data->color = 0;
  // ft_shell_starter(data);
}

void  ft_cleaner(t_data *data)
{
  free(data->input);
  // ft_free_arr(data->paths);
  // ft_data_prep(&data)
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
