/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:01:06 by yes-slim          #+#    #+#             */
/*   Updated: 2022/11/02 00:48:05 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	while (str[i] != (char)c && i > 0)
		i--;
	if (i == 0 && str[i] != (char)c)
		return (NULL);
	return ((char *)&str[i]);
}
