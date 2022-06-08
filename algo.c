/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/08 12:59:09 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lis(int *arr, int *max, int n, int	*lis)
{
	int	out;
	int	ending;
	int	i;

	ending = 1;
	out = 1;
	if (n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		out = fis(arr, max, i, lis);
		if (arr[i - 1] < arr[n - 1]
			&& out + 1 > ending)
		{
			ending = out + 1;
			lis[i + 1] += 1;
		}
		i++;
	}
	if (*max < ending)
		*max = ending;
	return (ending);
}
g);
}

int	fis(t_stack *stacks, int *max, int n, int porcamadonna)
{
	int out;
	int ending;
	int i;

	ending = 1;
	out = 1;
	if (n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		out = fis(stacks, max, i, porcamadonna + 1);
		if (stacks->stack_a[i - 1] < stacks->stack_a[n - 1] && out + 1 > ending)
		{
			ending = out + 1;
			stacks->lis[i] += 1;
		}
		i++;
	}
	if (*max < ending)
		*max = ending;
	return (ending);
}

int	wrapper(t_stack *stacks)
{
	//int	len;
	int	max;
	int porcamadonna = 0;

	int i = -1;
	max = 1;
	stacks->len_lis = lis(stacks, &max, stacks->len_a);
	printf("len lis = %d\n", stacks->len_lis);
	stacks->lis = allocation_helper(stacks->len_lis - 1);
	write(1, "porcamadonna\n", 14);
	// while (stacks->lis[++i])
	// 	printf("lis[%d]: %d", i, stacks->lis[i]);
	fis(stacks, &max, stacks->len_a, porcamadonna);
	while (i < stacks->len_lis - 1)
	{
		++i;
		printf("lis[%d]: %d\n", i, stacks->lis[i]);
	}
	i = -1;
	write(1,"diocane\n", 8);
//	printf("lis[0]: %d\n", stacks->lis[1]);
	while (stacks->lis[++i])
		printf("lis[%d]: %d\n", i, stacks->lis[i]);
	return max;
}

// int main(void)
// {
// 	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
// 	printf("lis: %d\n", wrapper(arr, 8));
// }