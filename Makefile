# Project name
NAME = minishell

# Readline name
READLINE = readline

# Compilator
CC = cc
# Compilator flags
CFLAGS = -Iincludes #-g3 -fsanitize=address 

# Libraries
LIB_PATH = readline/lib

# Headers
HEADERS = 	includes/minishell.h \
			includes/tokenization.h \
			includes/utilities.h

# Source directory
SRCS_DIR = sources/
# Objects directory
OBJS_DIR = objects/

# Source file names
SRCS_NAME = minishell.c \
			tokenization/tokenization.c \
			utilities/utilities_1.c

# Objects file names
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

# Compilation process
all: $(READLINE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -l$(READLINE) -L$(LIB_PATH)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/tokenization
	@mkdir -p $(OBJS_DIR)/utilities
	$(CC) $(CFLAGS) -c $< -o $@ 

# Configuring readline
$(READLINE):
	./config_readline readline

# Cleaning
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	rm -rf $(READLINE)
	make clean -C readline-8.2

# Remaking
re: clean all # when the readline issues are resolved, replace "clean" with "fclean".


# PHONY files
.PHONY: all clean fclean re
