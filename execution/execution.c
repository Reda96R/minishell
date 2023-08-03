/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:57:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/03 14:54:59 by YOUNES           ###   ########.fr       */
=======
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:57:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/03 17:38:01 by rerayyad         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	is_builtin(t_cmds *init)
{
	if (!strcmp(init->str[0], "pwd"))
		return (ft_pwd(init), 0);
	else if (!strcmp(init->str[0], "echo"))
		return (ft_echo(init), 0);
	else if (!strcmp(init->str[0], "cd"))
		return (ft_cd(init), 0);
	else if (!strcmp(init->str[0], "export"))
		return (ft_export(init), 0);
	// else if (!strcmp(init->str[0], "unset"))
		// return (ft_unset(), 0);
	else if (!strcmp(init->str[0], "env"))
		return (ft_env(init), 0);
	else if (!strcmp(init->str[0], "exit"))
		return (ft_exit(init), 0);
	return (1);
}

void	ft_execution(t_data *init)
{
	g_var.data->std_in = dup(0);
	g_var.data->std_out = dup(1);
	if (init->cmds)
	{
		init->cmds->str = ft_expander(init, init->cmds->str);
		printf ("%s\n", init->cmds->str[1]);
		if (!init->pipes)
			one_cmd(init->cmds);
		else
			multiple_cmds(init);
	}
}
