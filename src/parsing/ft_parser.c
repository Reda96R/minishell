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

void  ft_cmd_prep(t_parser parser, t_cmds *cmds)
{
}

void ft_parser(t_data *data)
{
  t_parser  parser;
  t_cmds    cmds;
  
  ft_parser_prep(data, &parser);
  while (parser.mylexer)
  {
    ft_cmd_prep(parser, &cmds);
    if (!cmds)
      error;
    ft_add_cmd(&data->cmds, cmds);
    parser.mylexer = parser.mylexer->next;
  }
}
