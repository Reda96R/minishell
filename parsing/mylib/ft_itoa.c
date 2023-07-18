/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:05:09 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/18 15:52:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mylib.h"

static int	ft_getlen(long n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n > 9)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;
	long	x;

	x = n;
	len = ft_getlen(x);
	str = (char *)malloc(sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	i = 0;
	if (x < 0)
	{
		x *= -1;
		str[0] = '-';
		i = 1;
	}
	while (len >= i)
	{
		str[len] = x % 10 + 48;
		x /= 10;
		len--;
	}
	return (str);
}
