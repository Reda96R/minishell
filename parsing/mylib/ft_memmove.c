/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:44:05 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/18 15:52:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mylib.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d = (unsigned char *) dst;
		s = (unsigned char *) src;
		while (len > 0)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	}
	else
	{
		d = (unsigned char *) dst + (len - 1);
		s = (unsigned char *) src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
