# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 20:26:22 by yes-slim          #+#    #+#              #
#    Updated: 2023/06/02 14:49:46 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = -I includes
CFLAGS = -Wall -Werror -Wextra $(HEADER) -c -fsanitize=address -g3
NAME = minishell
DEL = rm -f

SRCS =	$(addsuffix .c, $(addprefix , $())) \

OBJ = $(SRCS:.c=.o)

%.o : %.c
	@cc $(CFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) minishell.c
	@ar -rc minishell.a $(OBJ)
	@cc minishell.c minishell.a $(HEADER) -o $(NAME)
	@echo "\033[0;35m Your \033[0;33m$(NAME) \033[0;35mprogram is created \033[0m"

clean :
	@$(DEL) $(OBJ) philo.a
	@echo "\033[0;32mCleaning ....\033[0m"

fclean : clean
	@$(DEL) $(OBJ) $(NAME)

re : fclean all

.PHONY : all clean fclean re