#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static bool	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

void test_ft_issign()
{
    // Valid sign characters
    assert(ft_issign('-') == 1); // '-' should return true
    assert(ft_issign('+') == 1); // '+' should return true

    // Invalid characters
    assert(ft_issign('a') == 0); // Non-sign character
    assert(ft_issign('0') == 0); // Digit
    assert(ft_issign(' ') == 0); // Space
    assert(ft_issign(',') == 0); // Comma (ASCII 44)
    assert(ft_issign('\0') == 0); // Null character

    // Boundary checks
    assert(ft_issign('/') == 0); // Just before '+'
    assert(ft_issign('.') == 0); // Just after '-'

    printf("All tests for ft_issign passed.\n");
}

int main()
{
    test_ft_issign();
    return 0;
}
