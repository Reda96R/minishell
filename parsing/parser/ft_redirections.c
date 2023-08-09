/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:07:51 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/08 20:45:26 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_redirection(t_parser *parser, t_mylxr *tmp,
		int *node_id, t_data *data)
{
	t_mylxr	*new;

	if (!tmp->next->str)
		ft_errors_buster(3, data);
	ft_new_node(&new, tmp->token_id, ft_strdup(tmp->next->str));
	if (!new)
		ft_errors_buster(4, data);
	new->node_id = (*node_id)++;
	ft_add_node(&parser->redirections, new);
	ft_rm_node(&parser->mylexer, tmp->next->node_id);
	ft_rm_node(&parser->mylexer, tmp->node_id);
	parser->redirections_count++;
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
		ft_add_redirection(parser, tmp, node_id, data);
	ft_redirections(parser, data, node_id);
}
