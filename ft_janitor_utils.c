/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:22:15 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/13 10:39:00 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_pwd(t_data *data)
{
	if (data->pwd)
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	if (data->old_pwd)
	{
		free(data->old_pwd);
		data->old_pwd = NULL;
	}
}

void	ft_decontamination(t_data *data, int n)
{
	t_cmds	*tmp;
	t_cmds	*tmp0;

	(void) n;
	if (data->paths)
		ft_arr_free(data->paths);
	if (data->env)
		ft_arr_free(data->env);
	ft_free_pwd(data);
	tmp = data->cmds;
	tmp0 = data->cmds;
	while (tmp0)
	{
		if (tmp->str)
			ft_arr_free(tmp->str);
		if (tmp->redirections)
			ft_free_redierctions(tmp->redirections);
		tmp0 = tmp0->next;
		free (tmp);
		tmp = tmp0;
	}
	free(tmp);
}
