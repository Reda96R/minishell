#=============================VARIABLES========================================#
OS = $(shell uname -s)
NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC_DIR = src/
PAR_DIR = src/parsing/
EXEC_DIR = src/execution/
OBJ_DIR = obj/
MYLIB = src/mylib/mylib.a
MYPRINT = src/mylib/ft_printf/ft_printf.a
ifeq ($(OS), Darwin)
RDLIB = -L/Users/rerayyad/goinfre/homebrew/Cellar/readline/8.2.1/lib
RDINCLUDE = -I/Users/rerayyad/goinfre/homebrew/Cellar/readline/8.2.1/include
READLINE = -lreadline
else
READLINE = -lreadline -lncurses
endif

#=============================SHARED FILES=====================================#
FILES = minishell ft_janitor

#=============================PARSING FILES====================================#
FILES_P = ft_env_var ft_minishell_starter ft_quotes ft_tokens_scanner \
		  ft_lxr_utils ft_parser ft_parser_utils ft_redirections \

#=============================EXECUTION FILES==================================#
FILES_E = 

#=============================OBJs FILES=======================================#
OBJS = 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))\
		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_P)))\
		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_E)))

#=============================linker============================================#
all: os $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY)":::compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(MYLIB) $(MYPRINT) -o $(NAME) $(READLINE)
	@echo $(GREEN)":::Done:::\n"$(NONE)
	@echo $(GREEN)":::✅ $(NAME) is ready ✅:::"$(NONE)

#===========================cleaning===========================================#
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

#============================objects maker============================================#
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(CURSIVE)$(GRAY)":::Making object files:::" $(NONE)
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PAR_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(EXEC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@make -s -C src/mylib/
	@cc $(CFLAGS) -c $< -o $@

#=================================================================================#
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[0;31m'
YELLOW = '\033[0;33m'
CURSIVE='\033[3m'

os : 
	@echo $(YELLOW) "            _____         _____         ______        ____________" $(NONE)
	@echo $(YELLOW) "_______ ___ ___(_)_______ ___(_)___________  /_ _____ ___  /___  /" $(NONE)
	@echo $(YELLOW) "__  __ \__ \__  / __  __ \__  / __  ___/__  __ \_  _ \__  / __  /" $(NONE)
	@echo $(YELLOW) "_  / / / / /_  /  _  / / /_  /  _(__  ) _  / / //  __/_  /  _  /" $(NONE)
	@echo $(YELLOW) "/_/ /_/ /_/ /_/   /_/ /_/ /_/   /____/  /_/ /_/ \___/ /_/   /_/" $(NONE)
	@echo $(GREEN) "                                                               for $(OS)" $(NONE)
	
#=================================================================================#
