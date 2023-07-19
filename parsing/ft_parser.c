/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:10:13 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/19 07:10:58 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parsing/parser.h"

void  ft_parser_prep(t_data *data, t_parser *parser)
{
	parser->data = data;
	parser->mylexer = data->mylexer;
	parser->redirections = NULL;
	parser->redirections_count = 0;
}

void  ft_cmd_parser(t_parser *parser, t_cmds **cmd, t_data *data)
{
	char	**args;
	int		args_size;
	int		i;
	t_mylxr	*tmp;

	i = 0;
	ft_redirections(parser, data);
	args_size = ft_args_counter(parser->mylexer);
	args = (char **)malloc (sizeof (char *) * args_size + 1);
	if (!args)
		ft_errors_buster(4, data);
	tmp = parser->mylexer;
	while (args_size)
	{
		if (tmp->str)
		{
			args[i++] = ft_strdup(tmp->str);
			ft_rm_node(&parser->mylexer, tmp->node_id);
			tmp = parser->mylexer;
		}
		args_size--;
	}
	ft_new_cmd(parser, args, cmd, data);
}

void ft_parser(t_data *data)
{
  t_parser  parser;
  t_cmds    *cmd;
  
  cmd = NULL;
  data->cmds = NULL;
  while (data->mylexer)
  {
		if (data->mylexer && data->mylexer->token_id == PIPE)
			ft_rm_node(&data->mylexer, PIPE);
		ft_parser_prep(data, &parser);
		ft_cmd_parser(&parser, &cmd, data);
	// if (!cmd)
      // error;
		if (!data->cmds)
			data->cmds = cmd;
		else
			ft_add_cmd(&data->cmds, cmd);
		data->mylexer = parser.mylexer;
  }
}
