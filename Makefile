# --------------------------- Executable and Library ------------------------- #
NAME    = push_swap
LIBFT   = $(LIBDIR)/libft.a

# ----------------------------- Compiler Settings ---------------------------- #
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
# Uncomment and adjust if you want to use AddressSanitizer for debugging
# CFLAGS  = -fsanitize=address -g -O1 -Wall -Wextra -Werror

# --------------------------------- Folders ---------------------------------- #
SRCDIR  = src
OBJDIR  = obj
LIBDIR  = libft
INCDIR  = include

# ------------------------------ Source Files -------------------------------- #
SRCS = \
	$(SRCDIR)/main.c \
	$(SRCDIR)/init_stack.c \
	$(SRCDIR)/init_arr.c \
	$(SRCDIR)/circular_linked_list.c \
	$(SRCDIR)/utils.c \
	$(SRCDIR)/assign_index.c \
	$(SRCDIR)/commands_1.c \
	$(SRCDIR)/commands_2.c \
	$(SRCDIR)/commands_utils.c \
	$(SRCDIR)/sort.c \
	$(SRCDIR)/sort_two_five.c \
	$(SRCDIR)/error.c \
	$(SRCDIR)/sort_utils.c \
	$(SRCDIR)/validate.c \
	$(SRCDIR)/validate_utils.c

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# ------------------------------- Main Targets ------------------------------- #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -lft
	@echo -e "\033[32m\"$(NAME)\": successfully created!\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

# ------------------------------ Object Files -------------------------------- #
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $< -o $@

# ------------------------------- Clean Targets ------------------------------ #
clean:
	rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBDIR)
	@echo -e "\033[32m\"$(NAME)\": temporary files successfully removed!\033[0m"
	@echo ""


fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBDIR)
	@echo -e "\033[32m\"$(NAME)\": executable successfully removed!\033[0m"
	@echo ""



re: fclean all

# ---------------------------- Phony Declarations ---------------------------- #
.PHONY: all clean fclean re
