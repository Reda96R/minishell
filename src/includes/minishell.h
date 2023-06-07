#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "mylib.h"
# include "macros.h"

typedef struct s_data
{
  char  **vars;
  char  **paths;
  char  *pwd;
  char  *old_pwd;
  char  *input;
  int   color;

} t_data;

/*::: janitor :::*/
void  ft_errors_buster(int id);


/* -------------------Parsing-----------------------*/
/*::: env_vars :::*/
int   ft_env_setter(t_data *data, char **env);
void  ft_pwd_finder(t_data *data);
void	ft_paths_parser(t_data *data);
char	*ft_path_finder(char **vars);

/*::: shell_starter :::*/
void   ft_shell_starter(t_data *data);
int   ft_quotes_counter(char *input);
int   ft_quotes_matcher(char *input, int i, int quote);





/* -------------------Execution-----------------------*/




#endif
