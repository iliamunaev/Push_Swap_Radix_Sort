#include <stdio.h>
#include <assert.h>

static int ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f' || c == '\r' || c == '\t' || c == '\v');
}

void test_ft_isspace()
{
	// Test for valid whitespace characters
	assert(ft_isspace(' ') == 1);
	assert(ft_isspace('\n') == 1);
	assert(ft_isspace('\f') == 1);
	assert(ft_isspace('\r') == 1);
	assert(ft_isspace('\t') == 1);
	assert(ft_isspace('\v') == 1);

	// Test for non-whitespace characters
	assert(ft_isspace('a') == 0);
	assert(ft_isspace('1') == 0);
	assert(ft_isspace('-') == 0);
	assert(ft_isspace('+') == 0);
	assert(ft_isspace('\0') == 0);

	printf("ft_isspace: All tests passed successfully!\n");
}


int main()
{
	test_ft_isspace();
	return 0;
}
