/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:34:22 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/21 15:19:58 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr_base(unsigned long n, char *base, int *l)
{
	unsigned long		nbr;
	char				nbrs[100];
	int					len;
	int					i;

	nbr = n;
	len = ft_strlen_print(base);
	if (n == 0)
		ft_putchar('0', l);
	i = 0;
	while (nbr > 0)
	{
		nbrs[i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbrs[i], l);
}
