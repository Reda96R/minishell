/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:19:13 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/16 00:20:30 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "mylib.h"
# include "macros.h"
# include "structs.h"

/* --------------Global variable----------------- */
typedef struct s_glbl
{
	struct s_data	*data;
	unsigned char	exit_status;
	int				sig;
	int				hd_expansion;
}	t_glbl;

extern t_glbl	g_var;
/*------------------------------------------------*/
typedef struct s_data
{
	char	**paths;
	char	*pwd;
	char	*old_pwd;
	char	*input;
	int		color;
	int		pipes;
	char	**env;
	int		std_in;
	int		std_out;
	t_vars	*vars;
	t_mylxr	*mylexer;
	t_cmds	*cmds;
}	t_data;

void	ft_decontamination(t_data *data, int n);

/*::: janitor :::*/
void	ft_errors_buster(int id, t_data *data);
t_mylxr	*ft_node_clear(t_mylxr **node);
void	ft_lxr_cleaner(t_mylxr **mylexer);
void	ft_cmd_cleaner(t_cmds **cmds);

void	ft_error_exec(int id, char *str, int i);
void	ft_builtins_error(int id, char *str);

/* -------------------Parsing-----------------------*/
/*::: core functions :::*/
void	ft_shell_starter(t_data *data, int t);
int		ft_token_scanner(t_data *data);
void	ft_shell_reset(t_data *data);
void	ft_free_redierctions(t_mylxr *redirections);

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
char	*ft_rm_quote(char *str, char c, int n);
int		ft_check(t_data *data, int i, int *j, int r);

/*::: tokens :::*/
int		ft_token_parser(t_data *data, int *node_id, int id);
int		ft_token_identifier(t_data *data, int i);
int		ft_pipe_identifier(t_data *data, int i);
int		ft_redirection_identifier(t_data *data, int i);
int		ft_words_parser(t_data *data, int *node_id, int i);
void	ft_add_node(t_mylxr **mylxr, t_mylxr *new);
int		ft_new_node(t_mylxr **new, int id, char *str, int n);
void	ft_rm_node(t_mylxr **mylexer, int id);

/*::: parser :::*/
void	ft_parser(t_data *data);
void	ft_parser_prep(t_data *data, t_parser *parser);
void	ft_cmd_parser(t_parser *parser, t_cmds **cmd, t_data *data);
char	**ft_arr_dup(char **arr);
void	ft_new_cmd(t_parser *parser, char **str, t_cmds **cmd, t_data *data);
void	ft_add_cmd(t_cmds **cmds, t_cmds *cmd);
char	**ft_args_allocator(t_mylxr *mylexer, int *args_size);

/*::: redirections :::*/
void	ft_redirections(t_parser *parser, t_data *data, int	*node_id);
void	ft_add_redirection(t_parser *parser, t_mylxr *tmp, int *node_id,
			t_data *data);

/*::: expanding :::*/
char	**ft_expander(t_data *data, char **cmd, int n, int quote_protect);
char	*ft_normal_expand(char **cmd, int n, int *j, int i);
char	*ft_empty(void);
int		ft_spotter(char **cmd);
size_t	ft_dollar_s(char *str);
char	*ft_gold_finder(t_data *data, char *str);
int		ft_question_handler(char **str);
int		ft_digit_skipper(char *str, int n);
int		ft_translator(int i, char *str, char **tmp, t_data *data);
char	*ft_converter(char *cmd, char c, t_data *data, int *i);
char	**ft_skipper(char **cmd);
char	*ft_black_box(char *str);
char	*ft_quote_handler(char *cmd, int *j, int quote_protect);
char	*ft_single_quote(char *cmd, int *j, char r);
char	*ft_double_quote(char *cmd, int *j, char r);
char	*ft_dollar_in_quotes(char *tmp, int *j);
char	*ft_quote_hider(char *str, int *j, int r);

/* -------------------Execution-----------------------*/
/*::: Helpers :::*/
void	ft_execution(t_data *init);
char	*path_getter(t_cmds *init);
void	signals(void);
int		is_builtin(t_cmds *init);
void	one_cmd(t_cmds *init);
void	multiple_cmds(t_data *init);
void	ft_check_files(t_cmds *cmd);
int		_dprintf(int fd, const char *str, ...);
int		ft_heredoc(t_mylxr *del);

/*::: readline :::*/
void	rl_replace_line(const char *text, int clear_undo);

/*::: Libfts :::*/
int		_isdigit(int c);
int		_isalpha(int c);
int		_isalnum(int c);
int		_atoi(const char *str);
char	*_strjoin(char *s1, char *s2);
char	*_strdup(const char *src);
size_t	_strlen(const char *str);
int		_strcmp(char *s1, char *s2);
char	*_substr(char const *str, unsigned int start, size_t len);

/*::: Builtins :::*/
void	ft_pwd(t_cmds *init);
void	ft_exit(t_cmds *cmd);
void	ft_env(t_cmds *init);
int		ft_echo(t_cmds *init);
int		ft_cd(t_cmds *init);
void	ft_export(t_cmds *init);
void	ft_unset(t_cmds *init);

#endif
