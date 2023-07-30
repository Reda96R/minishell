/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:18 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/30 16:08:26 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_prep(t_data *data, t_parser *parser)
{
	parser->mylexer = data->mylexer;
	parser->redirections = NULL;
	parser->redirections_count = 0;
}

void	ft_cmd_parser(t_parser *parser, t_cmds **cmd, t_data *data)
{
	char	**args;
	int		args_size;
	int		i;
	t_mylxr	*tmp;
	int		node_id;

	i = 0;
	node_id = 0;
	ft_redirections(parser, data, &node_id);
	args_size = ft_args_counter(parser->mylexer);
	args = (char **)malloc (sizeof (char *) * args_size + 1);
	if (!args)
		ft_errors_buster(4, data);
	tmp = parser->mylexer;
	while (args_size)
	{
		if (tmp->str)
		{
			args[i] = ft_strdup(tmp->str);
			if (!args[i++])
				ft_errors_buster(4, data);
			ft_rm_node(&parser->mylexer, tmp->node_id);
			tmp = parser->mylexer;
		}
		args_size--;
	}
	args[i] = NULL;
	ft_new_cmd(parser, args, cmd, data);
}

void	ft_parser(t_data *data)
{
	t_parser	parser;
	t_cmds		*cmd;

	cmd = NULL;
	data->cmds = NULL;
	while (data->mylexer)
	{
		if (data->mylexer && data->mylexer->token_id == PIPE)
			ft_rm_node(&data->mylexer, data->mylexer->node_id);
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
