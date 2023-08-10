/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:33:55 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/09 11:56:08 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

/*===============T_VARS===================*/
typedef struct s_vars
{
	char		  *key;
	char		  *value;
	int			  node_id;
	struct s_vars *next;
	struct s_vars *prev;
} t_vars;


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
  char			**str;
  char          *herdoc_name;
  t_mylxr       *redirections;
  int           redirections_count;
  int			fd_in;
  int			fd_out;
  struct s_cmds *next;
  struct s_cmds *prev;
} t_cmds;

/*===============T_PARSER==================*/
typedef struct s_parser
{
  int     redirections_count;
  t_mylxr *mylexer;
  t_mylxr *redirections;
} t_parser;

/*=======================================*/
#endif
