/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:50:14 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/02 11:33:29 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mylib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	i = 0;
	j = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	dl = i;
	sl = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dl)
		return (sl + dstsize);
	while (src[j] && j < dstsize - dl - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dl + sl);
}
