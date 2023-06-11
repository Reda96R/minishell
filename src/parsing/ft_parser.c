/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:10:13 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/10 16:10:14 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void  ft_parser_prep(t_data *data, t_parser *parser)
{
  parser->data = data;
  parser->mylexer = data->mylexer;
  parser->rdirections = NULL;
}

void  ft_cmd_parser(t_parser *parser, t_cmds *cmd, t_data *data)
{
  char **args;
  int args_size;
  t_mylxr tmp;

  ft_redirections(parser, data);
  args_size = ft_args_counter(parser->mylexer);
  args = (char *)malooc (sizeof (char *) * args_size + 1);
  if (!args)
      ft_errors_buster(4, data);
  tmp = (*parser)->mylexer;
  while (tmp && arg_size > 0)
  {
    if (tmp->str)
    {
      args[i++] = ft_strdup(tmp->str);
      ft_rm_node(&parser->mylexer, tmp->node_id);
    }
    tmp = tmp->next;
    arg_size--;
  }
  ft_new_cmd(parser, str, &cmd, data);
}

void ft_parser(t_data *data)
{
  t_parser  parser;
  t_cmds    cmd;
  
  ft_parser_prep(data, &parser);
  while (parser.mylexer)
  {
    if (data->mylexer && data->mylexer->token_id == PIPE)
      ft_rm_node(&data->mylexer, PIPE);
    ft_cmd_parser(&parser, &cmd, data);
    if (!cmd)
      error;
    if (!data->cmds)
      data->clds = cmd;
    else
    ft_add_cmd(&data->cmds, &cmd);
    parser.mylexer = parser.mylexer->next;
  }
}
