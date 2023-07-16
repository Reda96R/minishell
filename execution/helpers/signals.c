/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:35:52 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/09 11:10:34 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	sighandel(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	signals(void)
{
	signal(SIGINT, sighandel);
	signal(SIGQUIT, SIG_IGN);
}
