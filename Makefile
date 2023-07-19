# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 13:54:21 by yes-slim          #+#    #+#              #
#    Updated: 2023/07/19 07:07:00 by rerayyad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========================OS============================#
OS			= $(shell uname -s)
#========================Readline============================#
ifeq ($(OS), Darwin)
READLINE 	= -lreadline
else
READLINE 	= -lreadline -lncurses
endif
#========================variables============================#
HEADER  	= -I includes $(RL_HEADER)
SANITIZ		= -g3 -fsanitize=address
CFLAGS 		= -Wall -Werror -Wextra $(HEADER) -c 
NAME    	= minishell
DEL     	= rm -rf
#=================parcing_files=======================================#
Pars 		= ft_env_var ft_minishell_starter ft_quotes ft_tokens_scanner \
		 	  ft_lxr_utils ft_parser ft_parser_utils ft_redirections
libft_pars  = parsing/mylib/mylib.a
Pars_SRCS   = $(addsuffix .c, $(addprefix parsing/, $(Pars))) 

#=================execution_files=======================================#
LIBFT   	= ft_strdup ft_strlen list_create list_delete
BUILTIN 	= ft_env ft_pwd #ft_echo ft_cd ft_export ft_unset ft_exit
HELPERS 	= $(addprefix builtins/, $(BUILTIN))\
		 	  $(addprefix libft/, $(LIBFT))\
		 	  init signals
Exec_SRCS   = $(addsuffix .c, $(addprefix execution/helpers/, $(HELPERS)))
#====================================================================#
OBJ     	= $(Exec_SRCS:.c=.o) $(Pars_SRCS:.c=.o) ft_janitor.o
#=========================compile=============================#
%.o     : %.c
		 @echo $(grey)$(italic)"	~Compiling $<"$(reset)
		 @cc $(CFLAGS) $< -o $@ 
#==========================rules==============================#
all     : os $(NAME)

$(NAME) : $(OBJ) minishell.c
		 @stty -echoctl
		 @ar -rc minishell.a $(OBJ)
		 @make -s -C parsing/mylib
		 @cc $(SANITIZ) minishell.c minishell.a $(libft_pars) $(HEADER) -o $(NAME) $(READLINE)
		 @echo $(bold)$(green)"	:::$(NAME) is ready:::"$(reset)

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
	@echo $(yellow) "            _____         _____         ______        ____________" $(reset)
	@echo $(yellow) "_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /" $(reset)
	@echo $(yellow) "__  __ \__ \__  / __  __ \__  / __  ___/__  __ \_  _ \__  / __  /" $(reset)
	@echo $(yellow) "_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /" $(reset)
	@echo $(yellow) "/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \___/ /_/   /_/" $(reset)
	@echo $(green) "                                                               for $(OS)" $(reset)
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
