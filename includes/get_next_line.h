/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:41:01 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/15 02:53:05 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minishell.h"

int		get_next_line(int fd, char **line);
char	*ft_fill(char *stock, int fd);
int		ft_search(char *str, int c);
char	*ft_line(char *src);
char	*ft_saver(char *stock);

#endif
