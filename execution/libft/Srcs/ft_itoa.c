/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:22:24 by yes-slim          #+#    #+#             */
/*   Updated: 2022/10/31 23:59:23 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INNT_MIN -2147483648

static char	*ft_rev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

static char	*ft_alloc(int n)
{
	char	*str;
	int		count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_special(int i)
{
	char	*str;

	if (i == 0)
		str = ft_strdup("0");
	if (i == INNT_MIN)
		str = ft_strdup("-2147483648");
	return (str);
}

static char	*ft_fill(int n, char *str)
{
	int	i;
	int	s;

	i = 0;
	s = n;
	if (n < 0)
	n *= -1;
	while (n != 0)
	{
		str[i] = ((n % 10) + 48);
		n = n / 10;
		i++;
	}
	if (s < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0 || n == INNT_MIN)
	{
		str = ft_special(n);
		return (str);
	}
	str = ft_alloc(n);
	if (!str)
		return (NULL);
	str = ft_fill(n, str);
	ft_rev(str);
	return (str);
}
