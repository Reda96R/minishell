/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _substr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:17:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/11 13:33:04 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*_substr(char const *str, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	if (!str)
		return (NULL);
	if (len > _strlen(str))
		len = _strlen(str);
	if (_strlen(str) - start <= len)
		len = _strlen(&str[start]);
	if (str[0] == '\0' || start >= _strlen(str))
		return (_strdup(""));
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (str[i] != '\0' && j < len)
	{
		subs[j] = str[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
