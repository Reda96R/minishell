/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:01:39 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/21 15:17:41 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../../fdf.h"

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *l);
void	ft_putnbr_base(unsigned long n, char *base, int *l);
void	ft_putstr(char *str, int *l);
void	ft_putnbr(int n, int *l);
int		ft_strlen_print(char *str);
int		ft_getlen(long n);
void	ft_adress(unsigned long long n, int *l);
int		ft_strchr_print(const char *s, int c);

#endif
