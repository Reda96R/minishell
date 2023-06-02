#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mylib.h"

typedef struct s_data
{
  char **vars;
  char  *pwd;
  char  *old_pwd;
} t_data;

/*::: env_vars :::*/
int ft_pwd_finder(t_data *data);

/*::: janitor :::*/
void  ft_errors_buster(int id);

#endif
