# Output executable
NAME = push_swap

# Compiler and flags
# TEST # gcc = gcc -fsanitize=address -g -O1
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRCDIR	= src
OBJDIR	= obj
LIBDIR	= libft
INCDIR	= include
LIBFT	= $(LIBDIR)/libft.a

# Source files and object files
SRCS	= $(SRCDIR)/main.c \
			(SRCDIR)/init_stack.c \
			(SRCDIR)/init_arr.c \
			(SRCDIR)/circular_linked_list.c \
			(SRCDIR)/utils.c \
			(SRCDIR)/assign_index.c \
			(SRCDIR)/commands_1.c \
			(SRCDIR)/commands_2.c \
			(SRCDIR)/commands_utils.c \
			(SRCDIR)/sort.c \
			(SRCDIR)/sort_two_five.c \
			(SRCDIR)/error.c \
			(SRCDIR)/sort_utils.c \
			(SRCDIR)/validate.c \
			(SRCDIR)/validate_utils.c

OBJS     = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# Rules
all: $(LIBFT) $(NAME)

# Build the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft
	@echo "\033[32m\"PUSH_SWAP\" is successfully created!\033[0m"

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $< -o $@

# Build the libft library
$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

# Clean object files
clean:
	rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBDIR)


# Clean all (object files and executable)
fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBDIR)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
