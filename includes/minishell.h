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

/* --------------Global variable----------------- */
typedef struct s_glbl
{
	int	error_status;
}	t_glbl;

t_glbl	g_var;
/*------------------------------------------------*/

typedef struct s_data
{
  char	  **paths;
  char	  *pwd;
  char	  *old_pwd;
  char	  *input;
  int	  color;
  int	  pipes;
  char	  **env;
  t_vars  *vars;
  t_mylxr *mylexer;
  t_cmds  *cmds;
} t_data;

/*::: janitor :::*/
void	ft_errors_buster(int id, t_data *data);
t_mylxr	*ft_node_clear(t_mylxr **node);
void	ft_lxr_cleaner(t_mylxr **mylexer);
void	ft_cmd_cleaner(t_cmds **cmds);

/* -------------------Parsing-----------------------*/
/*::: core functions :::*/
void	ft_shell_starter(t_data *data);
int		ft_token_scanner(t_data *data);
void	ft_shell_reset(t_data *data);

/*::: env_vars :::*/
int		ft_env_var(t_data *data, char **env, int n);
int		ft_env_setter(t_data *data, char **env, int n);
void	ft_pwd_finder(t_vars *vars, t_data *data);
void	ft_paths_parser(t_data *data);
char	*ft_path_finder(t_vars *vars);
void	ft_add_var(t_vars **vars, t_vars *new_n);
int		ft_new_var(t_vars **new_n, int node_id, char *str);
t_vars	*ft_var_clear(t_vars **node);
void	ft_rm_var(t_vars **vars, int id);

/*::: quotes :::*/
int		ft_quotes_counter(char *input);
int		ft_quotes_matcher(char *input, int i, int quote, int *quote_count);
int		ft_quote_skiper(char *str, int quote, int i);
char	*ft_rm_quote(char *str, char c);

/*::: tokens :::*/
int		ft_token_parser(t_data *data, int *node_id, int id);
int		ft_token_identifier(t_data *data, int i);
int		ft_words_parser(t_data *data, int *node_id, int i);
void	ft_add_node(t_mylxr **mylxr, t_mylxr *new);
int		ft_new_node(t_mylxr **new, int id, char *str);
void	ft_rm_node(t_mylxr **mylexer, int id);

/*::: parser :::*/
void	ft_parser(t_data *data);
void	ft_parser_prep(t_data *data, t_parser *parser);
void	ft_cmd_parser(t_parser *parser, t_cmds **cmd, t_data *data);
void	ft_new_cmd(t_parser *parser, char **str, t_cmds **cmd, t_data *data);
void	ft_add_cmd(t_cmds **cmds, t_cmds *cmd);
int		ft_args_counter(t_mylxr *mylexer);

/*::: redirections :::*/
void	ft_redirections(t_parser *parser, t_data *data);
void    ft_add_redirection(t_parser *parser, t_mylxr *tmp, int *node_id, t_data *data);

/*::: expanding :::*/
char	**ft_expander(t_data *data, char **cmd);
size_t	ft_dollar_s(char *str);
char	*ft_gold_finder(t_data *data, char *str);
int		ft_question_handler(char **str);
int		ft_digit_skipper(char *str, int n);
int		ft_translater(int i, char *str, char **tmp, t_data *data);

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
int		_isdigit(int c);
int		_atoi(const char *str);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
// t_env	*lstnew(void *key);
// t_env	*lstlast(t_env *lst);
// void	lst_add_back(t_env **lst, t_env *new);
// void	lstdelone(t_env *lst, void (*del)(void *));
// void	lstclear(t_env **lst, void (*del)(void *));

/*::: Builtins :::*/
void	ft_pwd(t_data *init);
void	ft_exit(t_cmds *cmd);
void	ft_env(t_cmds *init);
void	ft_echo(t_cmds *init);

#endif
