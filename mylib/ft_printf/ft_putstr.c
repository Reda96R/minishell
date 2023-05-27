/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:33:16 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/17 15:49:03 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putstr(char *str, int *l)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", l);
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], l);
}
