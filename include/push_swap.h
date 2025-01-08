#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ERROR_VALUE LLONG_MIN

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;

}			t_stacks;

// input validation
int	is_valid(int ac, char **av);
long long	ft_atoi_safe(char *s);
int	get_len(int ac, char **av);
int	ft_isspace(char c);


#endif
