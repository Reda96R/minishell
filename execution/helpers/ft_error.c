/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:19:11 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/10 20:48:20 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_error(char *str, int stat)
{
	printf("%s\n", str);
	exit(stat);
}

void	ft_janitor(t_init *init)
{

}
