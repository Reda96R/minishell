/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:29:42 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/21 15:08:21 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printer(char c, va_list arg)
{
	int	l;

	l = 0;
	if (c == 'c')
		ft_putchar(va_arg(arg, int), &l);
	else if (c == '%')
		ft_putchar('%', &l);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), &l);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), &l);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", &l);
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", &l);
	else if (c == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", &l);
	else if (c == 'p')
		ft_adress(va_arg(arg, unsigned long), &l);
	else
		ft_putchar(c, &l);
	return (l);
}

int	ft_printf(const char *format, ...)
{
	int		l;
	int		i;
	va_list	arg;

	va_start(arg, format);
	l = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr_print("cspdiuxX%", format[i + 1]))
			l += ft_printer(format[++i], arg);
		else if (format[i] != '%')
			ft_putchar(format[i], &l);
		i++;
	}
	va_end(arg);
	return (l);
}

