/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:07:51 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 09:38:40 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void	ft_normal_redirection(t_mylxr *tmp, t_data *data, t_mylxr **new)
{
	char	**cmd;
	char	**tmp0;

	*new = NULL;
	cmd = (char **)malloc (sizeof(char *) * 2);
	if (!cmd)
		ft_errors_buster(4, data);
	cmd[0] = (char *)malloc (sizeof(char) * (ft_strlen(tmp->next->str) + 1));
	if (!cmd[0])
	{
		free (cmd);
		ft_errors_buster(4, data);
	}
	cmd[1] = NULL;
	ft_strlcpy(cmd[0], tmp->next->str, ft_strlen(tmp->next->str) + 1);
	tmp0 = ft_expander(data, cmd, 0, 0);
	ft_new_node(new, tmp->token_id, *tmp0, 1);
	ft_arr_free(tmp0);
	// if (cmd[0])
		// free(cmd[0]);
}

void	ft_add_redirection(t_parser *parser, t_mylxr *tmp,
	int *node_id, t_data *data)
{
	t_mylxr	*new;
	char	*str;

	new = NULL;
	if (!tmp->next->str)
		ft_errors_buster(3, data);
	if (tmp->token_id != 5)
		ft_normal_redirection(tmp, data, &new);
	else
	{
		g_var.hd_expansion = !(tmp->next->str[0] == '\''
				|| tmp->next->str[0] == '\"');
		if (tmp->next->str[0] == '\'' || tmp->next->str[0] == '\"')
			ft_rm_quote(tmp->next->str, tmp->next->str[0], 1);
		str = ft_strdup(tmp->next->str);
		ft_new_node(&new, tmp->token_id, str, 0);
		free(str);
	}
	if (!new)
		ft_errors_buster(4, data);
	new->node_id = (*node_id)++;
	ft_add_node(&parser->redirections, new);
	ft_rm_node(&parser->mylexer, tmp->next->node_id);
	ft_rm_node(&parser->mylexer, tmp->node_id);
}

void	ft_redirections(t_parser *parser, t_data *data, int *node_id)
{
	t_mylxr	*tmp;

	tmp = parser->mylexer;
	while (tmp && !tmp->token_id)
		tmp = tmp->next;
	if (!tmp || tmp->token_id == PIPE)
		return ;
	if (!(tmp)->next)
		ft_errors_buster(3, data);
	if (tmp->token_id >= 2 && tmp->token_id <= 5)
	{
		ft_add_redirection(parser, tmp, node_id, data);
		parser->redirections_count++;
	}
	ft_redirections(parser, data, node_id);
}
