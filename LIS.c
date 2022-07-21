#include "push_swap.h"

int	*hash_init(int *arr, int len)
{
	int	i;

	arr = (int *)malloc(sizeof(int *) * len);
	if (!arr)
	{
		printf("error while allocating hash");
		exit(0);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}

void LIS(t_stack *stacks)
{
	int *hash;

	hash = hash_init(hash, stacks->len_lis);
	
}
