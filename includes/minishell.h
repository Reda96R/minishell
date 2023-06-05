#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mylib.h"

typedef struct s_data
{
  char  **vars;
  char  **paths;
  char  *pwd;
  char  *old_pwd;

} t_data;

/*::: env_vars :::*/
int   ft_env_setter(t_data *data, char **env);
void  ft_pwd_finder(t_data *data);
void	ft_paths_parser(t_data *data);
char	*ft_path_finder(char **vars);

/*::: janitor :::*/
void  ft_errors_buster(int id);

#endif
