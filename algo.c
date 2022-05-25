/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/25 13:14:14 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *stacks)
{
	//	allocation_helper(stacks->lis, stacks->len_a);
}

int	fis(t_stack *stacks, int *max, int n)
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
		out = fis(stacks->stack_a, max, i);
		if (stacks->stack_a[i - 1] < stacks->stack_a[n - 1]
			&& out + 1 > ending)
		{
			ending = out + 1;
			stacks->lis[i + 1] += 1;
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


	int i = -1;
	while (stacks->lis[++i])
		printf("lis[%d]: %d", i, stacks->lis[i]);
	max = 1;
	//len = stacks->len_a;
	fis(stacks, &max, stacks->len_a);
	i = -1;
	write(1,"diocane\n", 8);
	while (stacks->lis[++i])
		printf("lis[%d]: %d", i, stacks->lis[i]);
	return max;
}

// int main(void)
// {
// 	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
// 	printf("lis: %d\n", wrapper(arr, 8));
// }