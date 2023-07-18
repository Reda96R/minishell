/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:08:15 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/08 14:08:47 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLEXER_H
# define MYLEXER_H

#include "../minishell.h"

typedef struct s_mylxr
{
  char            *str;
  int             token_id;
  int             node_id;
  struct s_mylxr  *next;  
  struct s_mylxr  *prev;  
} t_mylxr;

#endif
