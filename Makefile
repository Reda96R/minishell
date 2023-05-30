OS = $(shell uname -s)
NAME = minishell
SRC_DIR = src/
OBJ_DIR = obj/
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
FILES = minishell 
MYLIB = mylib/mylib.a
MYPRINT = mylib/ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror #g -fsanitize=address 

all: os $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(MYLIB) $(MYPRINT) -o $(NAME)
	@echo $(GREEN)"::: $(NAME) is ready:::"$(NONE)

$(OBJS): $(SRC)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@mkdir -p $(OBJ_DIR)
	@make -s -C mylib/
	@cc $(CFLAGS) -c $(SRC) -o $@
	@echo $(GREEN)":::Done:::"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -rf $(OBJ_DIR)	
	@rm -f $(OBJS) 
	@make -s clean -C mylib/
	@echo $(RED)":::Deleted:::"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) 
	@make -s fclean -C mylib/
	@echo $(RED)":::All deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
CURSIVE='\033[3m'


os : 
	@echo $(YELLOW) "            _____         _____         ______        ____________" $(NONE)
	@echo $(YELLOW) "_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /" $(NONE)
	@echo $(YELLOW) "__  __ \`__ \__  / __  __ \__  / __  ___/__  __ \_  _ \__  / __  /" $(NONE)
	@echo $(YELLOW) "_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /" $(NONE)
	@echo $(YELLOW) "/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \___/ /_/   /_/" $(NONE)
	@#echo $(GREEN) "                                      " $(NONE)
	@echo $(GREEN) "                                                               for $(OS)" $(NONE)
