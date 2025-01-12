#include <stdio.h>
#include <assert.h>

int	get_len_arr(char ***arrs)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (arrs[i])
	{
		j = 0;
		while (arrs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}
// Test function
void test_get_len_arr()
{
    // Test 1: Basic valid input
    char *arr1_1[] = {"1", "2", NULL};
    char *arr1_2[] = {"3", "-4", "  -5", NULL};
    char *arr1_3[] = {"  42  ", NULL};
    char **arr1[] = {arr1_1, arr1_2, arr1_3, NULL};
    int result1 = get_len_arr(arr1);
    assert(result1 == 6);

    // Test 2: Single sub-array
    char *arr2_1[] = {"0", "1", "2", NULL};
    char **arr2[] = {arr2_1, NULL};
    int result2 = get_len_arr(arr2);
    assert(result2 == 3);


    // Test 5: Mixed valid and single-element sub-arrays
    char *arr5_1[] = {"1", NULL};
    char *arr5_2[] = {"-2", NULL};
    char *arr5_3[] = {"3", "4", "5", NULL};
    char **arr5[] = {arr5_1, arr5_2, arr5_3, NULL};
    int result5 = get_len_arr(arr5);
    assert(result5 == 5);

    printf("All tests passed successfully!\n");
}

int main()
{
    test_get_len_arr();
    return 0;
}
