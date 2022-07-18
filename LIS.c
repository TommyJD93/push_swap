#include "push_swap.h"

int	find_longest(int **matrix, int mat_x, int mat_y)
{
	int	cont;
	int	max;
	int	index;
	int	i;
	int	j;

	i = 0;
	max = 0;
	while (i < )
	{
		cont = 0;
		j = 0;
		while ()
		{
			/* code */
		}
		if (cont > max)
		{
			index = i;
		}
	}

}

void LIS(t_stack *stacks)
{
	int	**m;
	int	i; // x index
	int	j; // y iterator
	int	k; // y index
	int	res;

	j = 0;
	while (i < stacks->len_lis)
	{
		k = 1;
		i = 0;
		m[i][j] = stacks->lis[i];
		while (j < stacks->len_lis)
		{
			if (stacks->lis[j] > stacks->lis[i])
			{
				m[i][k] = stacks->lis[j];
				k++;
			}
			j++;
		}
		i++;
	}
	res = find_longest(m, ft_calc_);

}
