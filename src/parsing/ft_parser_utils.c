/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:06:34 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/11 16:06:35 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../includes/minishell.h"

int ft_args_counter(t_mylxr mylexer)
{
  t_mylxr tmp;
  int     i;

  i = 0;
  tmp = mylexer;
  while (tmp && tmp->token_id != PIPE)
  {
    if (tmp->node_id >= 0)
      i++;
    tmp = tmp->next;
  }
  return (i);
}


t_cmds  ft_new_cmd(t_parser *parser, char *str, t_cmds **cmd, t_data *data)
{
  cmd = (t_cmds *)malloc (sizeof (t_cmds));
  if (!cmd)
    ft_errors_buster(4, data);
  // (*cmd)->herdoc
  (*cmd)->str = str;
  (*cmd)->redirections = parser->redirections; 
  (*cmd)->redirections_count = parser->redirections_count; 
  (*cmd)->herdoc = NULL;
  (*cmd)->next = NULL;
  (*cmd)->prev = NULL;
}

void  ft_add_cmd(t_cmds **cmds, t_cmds *cmd)
{
  t_cmds *tmp;
  
  tmp = *cmds;
  if (&cmds)
  {
    *cmds = cmd;
    return ;
  }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = cmd;
  cmd->prev = tmp;
}
