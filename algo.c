/* ************************************************************************** */
/*                                                                      */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/08 15:43:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack_a |  50 |  3 | 10 | 7 | 40 |  80|
// purolis |  4  |  4 | 3  | 3 |  2 |  1 |
// -------------------------------
// flagged |  0  |  1 | 0  | 1 |  1 |  1 |
// |
// 4 4 3 3 2 	1
// 50 3 10 7 40 80
void	flag_manager(t_stack *stacks)
{
	int	i;
	int	j;
	int *arr;

	arr = allocation_helper(stacks->len_a, 1);
	i = stacks->len_lis;
	while (--i > -1)
	{
		j = i + 1;
		if (stacks->stack_a[i] < stacks->stack_a[j] && stacks->lis[i] > stacks->lis[j])
			arr[i] = 1;
		else
			arr[i] = 0;
		// else if (stacks->stack_a[i] > stacks->stack_a[j] ||stacks->lis[i] < stacks->lis[j] )
	}
	if (stacks->stack_a[stacks->len_lis - 2] < stacks->stack_a[stacks->len_lis - 1]
		&& stacks->lis[stacks->len_lis - 2] > stacks->lis[stacks->len_lis - 1])
		arr[stacks->len_lis - 1] = 1;
	i = -1;
	printf("---porcaccio il signore---\n");
	while (++i < stacks->len_lis)
		printf("%d\n", arr[i]);
}

int	_lis(int *arr, int len, int *lis)
{
	int	max;
	int	i;
	int	j;

	i = len;
	max = 0;
	while (--i > -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
			{
				max = find_max(lis, i);
				if (max > lis[j])
					lis[i] = max;
				else
					lis[i] = 1 + lis[j];
			}
			j++;
		}
	}
	max = find_max(lis, i);
	return(max);
}

int	lis(t_stack *stacks)
{
	int	max;
	int	i;

	printf("len_lis: %d\n", stacks->len_lis);
	// stacks->slave = allocation_helper(stacks->len_lis, 1);
	max = _lis(stacks->stack_a, stacks->len_a, stacks->lis);
	// printf("flagged[0]: %d\n", flagged[0]);
	printf("----slave----\n");
	i = -1;
	while (++i < stacks->len_lis)
		printf("%d\n", stacks->lis[i]);
	write(1, "a\n", 2);
	flag_manager(stacks);
	return (max);
}