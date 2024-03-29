/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:06:34 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/14 17:05:35 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_arr_dup(char **arr)
{
	char	**str;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (arr[len])
		len++;
	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		ft_errors_buster(4, g_var.data);
	while (arr[++i])
	{
		str[i] = ft_strdup(arr[i]);
		free(arr[i]);
		arr[i] = NULL;
	}
	str[i] = NULL;
	free(arr);
	return (str);
}

char	**ft_args_allocator(t_mylxr *mylexer, int *args_size)
{
	t_mylxr	*tmp;
	int		i;
	char	**args;

	i = 0;
	tmp = mylexer;
	while (tmp && tmp->token_id != PIPE)
	{
		if (tmp->node_id >= 0)
			i++;
		tmp = tmp->next;
	}
	args = (char **)malloc((sizeof (char *)) * (i + 1));
	if (!args)
		ft_errors_buster(4, g_var.data);
	*args_size = i;
	return (args);
}

void	ft_new_cmd(t_parser *parser, char **str, t_cmds **cmd, t_data *data)
{
	*cmd = (t_cmds *)malloc (sizeof (t_cmds));
	if (!cmd)
		ft_errors_buster(4, data);
	(*cmd)->herdoc_name = NULL;
	(*cmd)->str = ft_arr_dup(str);
	(*cmd)->redirections = parser->redirections;
	(*cmd)->redirections_count = parser->redirections_count;
	(*cmd)->hd_id = -3;
	(*cmd)->fd_in = 0;
	(*cmd)->fd_out = 1;
	(*cmd)->next = NULL;
	(*cmd)->prev = NULL;
}

void	ft_add_cmd(t_cmds **cmds, t_cmds *cmd)
{
	t_cmds	*tmp;

	tmp = *cmds;
	if (!cmds)
	{
		*cmds = cmd;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cmd;
	cmd->prev = tmp;
}
