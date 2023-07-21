#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "mylib.h"
# include "macros.h"
# include "structs.h"
# include <strings.h>
# include <limits.h>


typedef struct s_data
{
  char    **vars;
  char    **paths;
  char    *pwd;
  char    *old_pwd;
  char    *input;
  int     color;
  int     pipes;
  t_mylxr *mylexer;
  t_cmds  *cmds;
} t_data;

/*::: janitor :::*/
void    ft_errors_buster(int id, t_data *data);
t_mylxr	*ft_node_clear(t_mylxr **node);
void 	 ft_lxr_cleaner(t_mylxr **mylexer);
void  	ft_cmd_cleaner(t_cmds **cmds);

/* -------------------Parsing-----------------------*/
/*::: core functions :::*/
void    ft_shell_starter(t_data *data);
int     ft_token_scanner(t_data *data);
void	ft_shell_reset(t_data *data);

/*::: env_vars :::*/
int     ft_env_setter(t_data *data, char **env, int n);
void    ft_pwd_finder(t_data *data);
void	ft_paths_parser(t_data *data);
char	*ft_path_finder(char **vars);

/*::: quotes :::*/
int     ft_quotes_counter(char *input);
int     ft_quotes_matcher(char *input, int i, int quote, int *quote_count);
int     ft_quote_skiper(char *str, int quote, int i);

/*::: tokens :::*/
int     ft_token_parser(t_data *data, int *node_id, int id);
int     ft_token_identifier(t_data *data, int i);
int     ft_words_parser(t_data *data, int *node_id, int i);
void    ft_add_node(t_mylxr **mylxr, t_mylxr *new);
int     ft_new_node(t_mylxr **new, int id, char *str);
void    ft_rm_node(t_mylxr **mylexer, int id);

/*::: parser :::*/
void    ft_parser(t_data *data);
void    ft_parser_prep(t_data *data, t_parser *parser);
void    ft_cmd_parser(t_parser *parser, t_cmds **cmd, t_data *data);
void  	ft_new_cmd(t_parser *parser, char **str, t_cmds **cmd, t_data *data);
void    ft_add_cmd(t_cmds **cmds, t_cmds *cmd);
int     ft_args_counter(t_mylxr *mylexer);

/*::: redirections :::*/
void    ft_redirections(t_parser *parser, t_data *data);
void    ft_add_redirection(t_parser *parser, t_mylxr *tmp, int *node_id, t_data *data);



/* -------------------Execution-----------------------*/
/*::: Helpers :::*/
void	ft_execution(t_data *init);
void	signals(void);
int		is_builtin(t_cmds *init);
void	one_cmd(t_data *init);
void	multiple_cmds(t_data *init);
void	path_getter(t_data *init);

/*::: readline :::*/
void 	rl_replace_line (const char *text, int clear_undo);

/*::: Libfts :::*/
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
// t_env	*lstnew(void *key);
// t_env	*lstlast(t_env *lst);
// void	lst_add_back(t_env **lst, t_env *new);
// void	lstdelone(t_env *lst, void (*del)(void *));
// void	lstclear(t_env **lst, void (*del)(void *));

/*::: Builtins :::*/
void	ft_pwd(void);
void	ft_exit(t_cmds *cmd);

#endif
