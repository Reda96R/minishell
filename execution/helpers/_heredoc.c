/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:32:30 by YOUNES            #+#    #+#             */
/*   Updated: 2023/08/10 15:23:07 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_wait_hd(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 3)
			g_var.exit_status = 131;
		if (WTERMSIG(status) == 2)
			g_var.exit_status = 130;
	}
}

char	*ft_heredoc_core(t_mylxr *del, char *str)
{
	char	**tmp;

	if (!_strcmp(del->str, str))
		exit (0);
	if (g_var.hd_expansion)
	{
		tmp = (char **)malloc(sizeof(char *) * 2);
		if (!tmp)
			ft_errors_buster(4, g_var.data);
		tmp[0] = ft_strdup(str);
		if (!tmp[0])
		{
			free(tmp);
			ft_errors_buster(4, g_var.data);
		}
		tmp[1] = NULL;
		tmp = ft_expander(g_var.data, tmp, 0);
		free(str);
		str = tmp[0];
	}
	return (str);
}

int	ft_heredoc(t_mylxr *del)
{
	int		pp[2];
	char	*str;
	pid_t	pid;

	pipe(pp);
	pid = fork();
	if (pid == 0)
	{	
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			str = readline("> ");
			if (!str)
			{
				printf("\n");
				exit(0);
			}
			if (!_strcmp(str, del->str))
				exit(0);
			// _dprintf(pp[1], "%s\n", ft_heredoc_core(del, str));
			_dprintf(pp[1], "%s\n", str);
			free(str);
		}
	}
	ft_wait_hd(pid);
	close(pp[1]);
	return (pp[0]);
}
