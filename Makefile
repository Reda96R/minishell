# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 10:18:48 by yes-slim          #+#    #+#              #
#    Updated: 2023/08/16 11:56:59 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========================OS============================#
OS			= $(shell uname -s)
#========================Readline============================#
ifeq ($(OS), Darwin)
READLINE 	= -L ~/goinfre/homebrew/Cellar/readline/8.2.1/lib/ -lreadline
RL_HEADER 	= -I ~/goinfre/homebrew/Cellar/readline/8.2.1/include/readline/
else
READLINE 	= -lreadline -lncurses
endif
#========================variables============================#
HEADER  	= -I includes $(RL_HEADER)
SANITIZ		= #-fsanitize=address
CFLAGS 		= -Wall -Werror -Wextra -g3 $(SANITIZ) $(HEADER) -c 
NAME    	= minishell
DEL     	= rm -rf
#=================parsing_files=======================================#
STRT 		= ft_minishell_starter
EXP 		= ft_expander ft_expander_utils ft_expander_utils_2 ft_expander_utils_3
LXR 		= ft_quotes ft_tokens_scanner ft_lxr_utils
PAR         = ft_env_var ft_env_vars_utils ft_parser ft_parser_utils ft_redirections
libft_pars  = parsing/mylib/mylib.a
PARS 		= $(addprefix expander/, $(EXP))\
			  $(addprefix lexer/, $(LXR))\
			  $(addprefix parser/, $(PAR))\
			  $(STRT)

Pars_SRCS   = $(addsuffix .c, $(addprefix parsing/, $(PARS))) 

#=================execution_files=======================================#
LIBFT   	= _strdup _strlen _atoi _isdigit _isalpha _isalnum _strjoin _strcmp _substr
BUILTIN 	= ft_pwd ft_exit ft_env ft_echo ft_cd ft_export ft_unset export_helpers cd_helpers
HELPERS 	= signals path_getter one_cmd check_files _dprintf multiple_cmds _heredoc mutiple_cmds_helpers
EXEC		= execution \
			  $(addprefix builtins/, $(BUILTIN)) \
		 	  $(addprefix libft/, $(LIBFT)) \
		 	  $(addprefix helpers/, $(HELPERS))
			  
Exec_SRCS   = $(addsuffix .c, $(addprefix execution/, $(EXEC)))
#====================================================================#
OBJ     	= $(Exec_SRCS:.c=.o) $(Pars_SRCS:.c=.o) ft_janitor.o ft_exec_janitor.o ft_janitor_utils.o
#=========================compile=============================#
%.o     : %.c
		 @echo $(grey)$(italic)"	~Compiling $<"$(reset)
		 @gcc-11 $(CFLAGS) $< -o $@ 
#==========================rules==============================#
all     : os $(NAME)

$(NAME) : $(OBJ) minishell.c
		 @stty -echoctl
		 @ar -rc minishell.a $(OBJ)
		 @make -s -C parsing/mylib
		 @gcc-11 $(SANITIZ) minishell.c minishell.a $(libft_pars) $(HEADER) -o $(NAME) $(READLINE)
		 @echo $(green)$(bold)":::$(NAME) is ready:::"$(reset)

clean  :
		 @echo $(grey)$(italic)$(bold)":::Deleting object files:::"$(reset)
		 @$(DEL) $(OBJ) minishell.a
		 @make clean -s -C parsing/mylib 
		 @echo $(red)$(bold)":::Deleted:::"$(reset)

fclean : clean
		 @echo $(grey)$(italic)$(bold)":::Deleting executeables:::"$(reset)
		 @$(DEL) $(NAME)
		 @make fclean -s -C parsing/mylib 				
		 @echo $(red)$(bold)":::All deleted:::"$(reset)

re 	  : fclean all

.PHONY	: all clean fclean re
#===========================OS================================#
os : 
	@echo $(grey) "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     " $(reset)
	@echo $(grey) "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     " $(reset)
	@echo $(grey) "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     " $(reset)
	@echo $(grey) "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     " $(reset)
	@echo $(grey) "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗" $(reset)
	@echo $(grey) "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" $(reset)
	@echo $(yellow) "                                                               for $(OS)" $(reset)

#===========================colors============================#
black  		= "\033[0;30m"
red    		= "\033[0;31m"
green  		= "\033[0;32m"
yellow 		= "\033[0;33m"
blue   		= "\033[0;34m"
purple		= "\033[0;35m"
cyan  		= "\033[0;36m"
grey   		= "\033[0;90m"
reset  		= "\033[0m"
#============================font=============================#
bold     	= "\033[1m"
italic    	= "\033[3m"
underline 	= "\033[4m"
inverse   	= "\033[7m"
#=============================================================#
