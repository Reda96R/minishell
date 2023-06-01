/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:46:22 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/17 15:48:36 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr(int n, int *l)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*l = 11;
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		*l += 1;
		ft_putnbr(-n, l);
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10), l);
		ft_putnbr((n % 10), l);
	}
	else
		ft_putchar(n + 48, l);
}
