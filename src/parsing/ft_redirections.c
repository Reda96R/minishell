/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:07:51 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/11 15:07:52 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

void  ft_add_redirection(t_parser *parser, t_mylxr *tmp, int *node_id, t_data* data)
{
  t_mylxr *new;

  ft_new_node(&new, tmp->token_id, ft_strdup(tmp->next->str));
  if (!new)
    ft_errors_buster(4, data);
	new->node_id = (*node_id)++;
  ft_add_node(&parser->redirections, new);
  ft_rm_node(&parser->mylexer, tmp->next->token_id);
  ft_rm_node(&parser->mylexer, tmp->token_id);
  parser->redirections_count++;
}

void  ft_redirections(t_parser *parser, t_data *data)
{
  t_mylxr *tmp;
  int     node_id;

  tmp = parser->mylexer;
  while (tmp && !tmp->token_id)
    tmp = tmp->next;
  if (!tmp || tmp->token_id == PIPE)
    return ;
  if (!(tmp)->next)
  {
    ft_errors_buster(3, data);
    // exit (0);
  }
  if (tmp->token_id >= 2 && tmp->token_id <= 5)
    ft_add_redirection(parser, tmp, &node_id, data);
  ft_redirections(parser, data);
}
