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

// stack_a |  50 |  3 | 10 | 7 | 40 |  80| 27 |  1|
// purolis |  4  |  4 | 3  | 3 |  2 |  1 |  1 |  1|
// -------------------------------
// flagged |  0  |  1 | 0  | 1 |  1 |  1 |
// |
// 4 4 3 3 2 	1
// 50 3 10 7 40 80
// 1 expected in indexes: 1, 3, 4, 5



void	flag_manager(t_stack *stacks)
{
	int	i;
	int	j;
	int prev;
	int *arr;

	arr = allocation_helper(stacks->len_a, 0);
	i = 0;
	prev = 0;
	while (i < stacks->len_lis)
	{
		j = i + 1;
		if (stacks->stack_a[i] < stacks->stack_a[j] && stacks->lis[i] > stacks->lis[j])
		{
			arr[i] = 1;
			prev = i;
		}
		else
		{
			if (stacks->lis[i] == 1 && stacks->lis[j] == 1 && stacks->stack_a[i] > stacks->stack_a[j]
				&& stacks->stack_a[i] > stacks->stack_a[prev])
			{
				arr[i] = 1;
				prev = i;
			}
			else
				arr[i] = 0;
		}
		i++;
	}
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

// shitty condition
// if (stacks->lis[i] > stacks->lis[j])
// {
// 	printf("comparing %d (stack_a[%d]) with  %d (stack_a[%d])\n", stacks->stack_a[i], i,stacks->stack_a[j], j);
// 	printf("comparing %d (lis[%d]) with  %d (lis[%d])\n", stacks->lis[i], i, stacks->lis[j], j);
// 	if (stacks->stack_a[i] < stacks->stack_a[j])
// 	{
// 		arr[i] = 1;
// 		printf("value 1 has been assigned to arr[%d]\n", i);
// 	}
// 	else
// 	{
// 		arr[i] = 0;
// 		printf("value 0 has been assigned to arr[%d]\n", i);
// 	}
// }
// else if ((stacks->lis[i] && stacks->lis[j]) == 1)
// {
// 	printf("comparing %d (stack_a[%d]) with  %d (stack_a[%d])\n", stacks->stack_a[i], i,stacks->stack_a[j], j);
// 	printf("comparing %d (lis[%d]) with  %d (lis[%d])\n", stacks->lis[i], i, stacks->lis[j], j);
// 	write(1, "a\n", 2);
// 	if (stacks->stack_a[i] < stacks->stack_a[j])
// 	{
// 		arr[i] = 1;
// 		printf("value 1 has been assigned to arr[%d]\n", i);
// 	}
// 	else
// 	{
// 		arr[i] = 0;
// 		printf("value 0 has been assigned to arr[%d]\n", i);
// 	}
// }
