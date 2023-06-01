/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:51:46 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/09 18:53:45 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mylib.h"

static size_t	ft_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i + 1);
}

static char	*ft_fill(const char *s, char c, size_t *j)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	*j += len;
	return (str);
}

static int	ft_alloc(char const *s, char **strs, char c, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (s[j] == c && s[j])
			j++;
		strs[i] = ft_fill(&s[j], c, &j);
		if (!strs[i])
			return (0);
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	size;
	int		i;

	if (!s)
		return (0);
	size = ft_size(s, c);
	strs = (char **)malloc(sizeof (char *) * size);
	if (!strs)
		return (NULL);
	strs[size - 1] = 0;
	i = 0;
	if (!ft_alloc(s, strs, c, size))
	{
		while (strs[i])
			free(strs[i++]);
		free(strs);
		return (0);
	}
	return (strs);
}
