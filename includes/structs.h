/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:33:55 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/20 18:44:57 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

/*===============T_MYLXR==================*/
typedef struct s_mylxr
{
  char            *str;
  int             token_id;
  int             node_id;
  struct s_mylxr  *next;  
  struct s_mylxr  *prev;  
} t_mylxr;

/*===============T_CMDS==================*/
typedef struct s_cmds
{
  char          **str;
  char          *herdoc;
  t_mylxr       *redirections;
  int           redirections_count;
  // builtins
  struct s_cmds *next;
  struct s_cmds *prev;
} t_cmds;

/*===============T_PARSER==================*/
typedef struct s_parser
{
  int     redirections_count;
  t_mylxr *mylexer;
  t_mylxr *redirections;
  struct s_data *data;
} t_parser;

/*=======================================*/
#endif