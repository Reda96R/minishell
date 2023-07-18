/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:23:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/09 11:10:39 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/*=======================Structs==============================*/

typedef struct m_env
{
	char			*key;
	struct m_env	*next;
}	t_env;

typedef struct s_init
{
	char	**m_env;
	t_env	*t_env;
}	t_init;

/*=======================Readline=============================*/
void	rl_replace_line(const char *str, int i);
/*=======================Builtins=============================*/
void	ft_env(t_init *init);
void	ft_pwd(void);
/*=======================Helpers==============================*/
void	ft_init(t_init *init, char **env);
void	signals(void);
/*=======================LIBFT================================*/
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
t_env	*lstnew(void *key);
t_env	*lstlast(t_env *lst);
void	lst_add_back(t_env **lst, t_env *new);
void	lstdelone(t_env *lst, void (*del)(void *));
void	lstclear(t_env **lst, void (*del)(void *));
/*============================================================*/
#endif