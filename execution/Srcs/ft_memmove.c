/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:25:11 by yes-slim          #+#    #+#             */
/*   Updated: 2022/10/31 23:53:25 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *sr, size_t n)
{
	size_t			len;
	unsigned char	*dest;
	unsigned char	*src;

	if (!dst && !sr)
		return (NULL);
	dest = (unsigned char *)dst;
	src = (unsigned char *)sr;
	len = n;
	if (dest > src)
	{
		while (len > 0)
		{
			len--;
			dest[len] = src[len];
		}
	}
	else
		ft_memcpy(dst, sr, n);
	return ((void *)dest);
}
