# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 13:54:21 by yes-slim          #+#    #+#              #
#    Updated: 2023/07/15 12:46:42 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#========================Readline============================#
RL_HEADER 	= -I ~/goinfre/homebrew/Cellar/readline/8.2.1/include/readline/
RL_LIB  	= -L ~/goinfre/homebrew/Cellar/readline/8.2.1/lib/ -lreadline
#========================variables============================#
HEADER  	= -I includes $(RL_HEADER)
SANITIZ		= -fsanitize=address
CFLAGS 		= -Wall -Werror -Wextra $(HEADER) -c #$(SANITIZ)
NAME    	= execution
DEL     	= rm -rf
#=================files=======================================#
LIBFT   	= ft_strdup ft_strlen list_create list_delete
BUILTIN 	= ft_env ft_pwd #ft_echo ft_cd ft_export ft_unset ft_exit
HELPERS 	= $(addprefix builtins/, $(BUILTIN))\
		 	  $(addprefix libft/, $(LIBFT))\
		 	  init signals
SRCS    	= $(addsuffix .c, $(addprefix helpers/, $(HELPERS))) \

OBJ     	= $(SRCS:.c=.o)
#=========================compile=============================#
%.o 		: %.c
			@echo $(grey)$(italic)"	~Compiling $<"$(reset)
			@cc $(CFLAGS) $< -o $@
#==========================rules==============================#
all 		: $(NAME)

$(NAME) 	: $(OBJ) execution.c
				@stty -echoctl
				@ar -rc execution.a $(OBJ)
				@cc execution.c execution.a $(HEADER) -o $(NAME) $(RL_LIB)
				@echo $(cyan)$(underline)"execution is ready to run" $(reset)

clean 		:
				@$(DEL) obj_dir execution.a
				@echo $(green)$(italic)$(bold)"	~Deleting files..."$(reset)

fclean 		: clean
				@$(DEL) $(NAME)
				@echo $(green)$(italic)$(bold)"	~Deleting execution..."$(reset)

re 			: fclean all

.PHONY 		: all clean fclean re
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