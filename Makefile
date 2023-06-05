OS = $(shell uname -s)
NAME = minishell
SRC_DIR = src/
PAR_DIR = src/parsing/
EXEC_DIR = src/execution/
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))\
			 $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_P)))\
			 $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_E)))

FILES = minishell ft_janitor
FILES_P = ft_env_var
FILES_E = 
MYLIB = src/mylib/mylib.a
MYPRINT = src/mylib/ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address 
RDLIB = /Users/rerayyad/goinfre/homebrew/Cellar/readline/8.2.1/lib
RDINCLUDE = /Users/rerayyad/goinfre/homebrew/Cellar/readline/8.2.1/include/

all: os $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY)":::Making object files:::" $(NONE)
	@echo $(GREEN)":::Done:::\n"$(NONE)
	@echo $(CURSIVE)$(GRAY)":::Compiling $(NAME):::" $(NONE)
	@cc -lreadline $(CFLAGS) $(OBJS) $(MYLIB) $(MYPRINT) -o $(NAME)
	@echo $(GREEN)":::✅ $(NAME) is ready ✅:::"$(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PAR_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc -lreadline $(CFLAGS) $(RDLIB) $(RDINCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(EXEC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -rf $(OBJ_DIR)	
	@make -s clean -C src/mylib/
	@echo $(RED)":::Deleted:::"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) 
	@make -s fclean -C src/mylib/
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
	@echo $(GREEN) "                                                               for $(OS)" $(NONE)
