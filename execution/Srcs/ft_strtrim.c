/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:25:27 by yes-slim          #+#    #+#             */
/*   Updated: 2022/11/02 15:32:35 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_front(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	check_back(char const *s, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s) - 1;
	j = 0;
	while (set[j] != '\0')
	{
		if (s[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	size_t	l;
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (NULL);
	l = 0;
	i = check_front(s, set);
	if (s[l] == '\0' || i == ft_strlen(s))
		return (ft_strdup(""));
	j = check_back(s, set);
	str = malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i <= j)
	{
		str[l] = s[i];
		i++;
		l++;
	}
	str[l] = '\0';
	return (str);
}
