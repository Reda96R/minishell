/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:16:01 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/02 11:39:35 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mylib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!haystack && len == 0)
		return (NULL);
	str = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
