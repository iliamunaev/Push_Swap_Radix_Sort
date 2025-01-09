# Output executable
NAME = push_swap

# Compiler and flags
# TEST # CC = cc -fsanitize=address -g -O1
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR	= src
OBJDIR	= obj
LIBDIR	= libft
INCDIR	= include
LIBFT	= $(LIBDIR)/libft.a

# Source files and object files
SRCS	= $(SRCDIR)/main.c \
			(SRCDIR)/init_stack.c \
			(SRCDIR)/utils.c


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
