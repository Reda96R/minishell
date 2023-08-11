/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:33 by yes-slim          #+#    #+#             */
/*   Updated: 2022/11/02 00:01:59 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str && len == 0)
		return (NULL);
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' && (i + j) < len)
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
