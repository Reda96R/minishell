# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:00:51 by rerayyad          #+#    #+#              #
#    Updated: 2022/10/29 14:48:32 by rerayyad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = mylib.a
FILES = ft_isdigit.c ft_isalnum.c ft_atoi.c ft_strrchr.c ft_striteri.c \
				ft_split.c ft_calloc.c ft_strjoin.c ft_strmapi.c ft_isalpha.c \
				ft_bzero.c ft_strlcat.c ft_isascii.c ft_isprint.c ft_strlcpy.c \
				ft_strncmp.c ft_strdup.c ft_itoa.c ft_memchr.c ft_memcmp.c \
				ft_memmove.c ft_memcpy.c  ft_strchr.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_strnstr.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c\
				get_next_line.c 
OBJS = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

all: $(NAME)

%.o: %.c
	@make -s -C ft_printf/
	@cc $(CFLAGS) -c $<
	@$(AR) $(NAME) $@

$(NAME): $(OBJS)

clean:
	@rm -f $(OBJS)
	@make -s clean -C ft_printf/

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C ft_printf/

re: fclean all

.PHONY:all clean fclean re 
