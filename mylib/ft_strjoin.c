/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:15 by rerayyad          #+#    #+#             */
/*   Updated: 2022/10/29 12:47:51 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mylib.h"
//#include <stddef>

char	*ft_strjoin(char const *s1, char const *s2)
{
  size_t  i;
  size_t  j;
  char    *str;

  i = 0;
  j = 0;
       str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
       if (!str)
       {
               free((char *)s1);
               return (NULL);
       }
       while (s1 && s1[j] != '\0')
               str[i++] = s1[j++];
  j = 0;
        while (s2 && s2[j] != '\0')
                str[i++] = s2[j++];
        str[i] = '\0';
        free((char *)s1);
        return (str);
}
