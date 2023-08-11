/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:54:50 by yes-slim          #+#    #+#             */
/*   Updated: 2022/10/31 23:59:18 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcount(char const *s, char c)
{
	int	wc;
	int	i;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static void	ft_free(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static char	*fillwrd(const char *s, char c, int start)
{
	int		i;
	int		len;
	char	*tab;

	i = 0;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

static	char	**ft_fillarr(const char *s, char **arr, int wc, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (wc != 0)
	{
		while (s[i] && s[i] == c)
			i++;
		arr[x] = fillwrd(s, c, i);
		if (!arr[x])
		{
			ft_free(arr, x);
			return (NULL);
		}
		x++;
		while (s[i] && s[i] != c)
			i++;
		wc--;
	}
	arr[x] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**arr;

	if (!s)
		return (NULL);
	wc = ft_wrdcount(s, c);
	arr = malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_fillarr(s, arr, wc, c);
	return (arr);
}
