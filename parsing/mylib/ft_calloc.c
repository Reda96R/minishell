/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/18 15:52:30 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mylib.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	str = (char *)malloc(count * size);
	i = 0;
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
