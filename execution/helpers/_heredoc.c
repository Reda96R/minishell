/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:32:30 by YOUNES            #+#    #+#             */
/*   Updated: 2023/08/16 12:07:53 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	ft_wait_hd(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_var.exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		if (WTERMSIG(status) == 2)
			g_var.exit_status = 1;
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
		tmp[1] = NULL;
		tmp = ft_expander(g_var.data, tmp, 0, 1);
		if (!tmp[0])
		{
			free(tmp);
			free(str);
			return (ft_strdup("\0"));
		}
		free(str);
		str = tmp[0];
		free(tmp);
	}
	return (str);
}

void	ft_child(int *pp, char *str, t_mylxr *del)
{
	dup2(g_var.data->std_in, 0);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_DFL);
	while (1)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		str = ft_heredoc_core(del, str);
		_dprintf(pp[1], "%s\n", str);
		free(str);
	}
}

int	ft_heredoc(t_mylxr *del)
{
	int		pp[2];
	char	*str;
	pid_t	pid;

	pipe(pp);
	str = NULL;
	pid = fork();
	if (pid == 0)
		ft_child(pp, str, del);
	ft_wait_hd(pid);
	close(pp[1]);
	return (pp[0]);
}
