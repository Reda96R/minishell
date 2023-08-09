/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:28:20 by rerayyad          #+#    #+#             */
/*   Updated: 2023/08/09 15:31:42 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mylib.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		l;
	int		i;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	i = 0;
	s = (char *)malloc(sizeof (char) * l + 1);
	if (!s)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
