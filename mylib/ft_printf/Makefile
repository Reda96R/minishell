# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:23:06 by rerayyad          #+#    #+#              #
#    Updated: 2022/11/20 14:58:13 by rerayyad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
FILES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_strlen_print.c ft_getlen.c ft_address.c ft_putnbr.c ft_strchr_print.c
OBJS = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

all: $(NAME)

%.o: %.c
	@cc $(CFLAGS) -c $<
	@$(AR) $(NAME) $@

$(NAME): $(OBJS)


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re 
