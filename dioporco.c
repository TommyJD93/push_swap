/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioporco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:38:20 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/27 16:06:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_maxx(int *arr, int len)
{
	int	max;
	int	i;

	max = arr[0];
	i = 0;
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	solve_three(t_stack stacks)
{
	int	max;
	//int i;

	max = find_maxx(stacks.stack_a, stacks.len_a);
	while (stacks.stack_a[0] != max)
	{
		write(1, "a\n", 2);
		// printf("stack_a[0]: %d\n", stacks.stack_a[0]);
		// printf("max: %d\n", max);
		//printf("---stack a---\n");
		//i = -1;
		// while (stacks.stack_a[++i])
		// 	printf("%d\n", stacks.stack_a[i]);
		sleep(5);
		rotate_a(&stacks);
	}
	push_b(&stacks);
	find_maxx(stacks.stack_a, stacks.len_a - 1);
	if (stacks.stack_a[0] == max)
		push_a(&stacks);
	if (stacks.stack_a[1] == max)
	{
		rotate_a(&stacks);
		push_a(&stacks);
	}
}

// void	solve_five(t_stack stacks)
// {

// }
