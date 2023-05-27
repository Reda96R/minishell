/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:34:33 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/17 15:13:34 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_adress(unsigned long long n, int *l)
{
	ft_putstr("0x", l);
	ft_putnbr_base(n, "0123456789abcdef", l);
}
