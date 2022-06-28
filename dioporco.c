/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioporco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:38:58 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/28 17:35:44 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//does the same thing as find_max, or at least i think so->->-> that's why I created a new one
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

void	solve_three(t_stack *stacks)
{
	int	max;
	int i = 0;

	max = find_maxx(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != max)
		rotate_a(stacks);
	printf("stack_a[0]: %d\n", stacks->stack_a[0]);
	printf("stack_a[1]: %d\n", stacks->stack_a[1]);
	printf("stack_a[2]: %d\n", stacks->stack_a[2]);

	push_b(stacks);

	printf("pushed_b\n");
	printf("stack_a[0]: %d\n", stacks->stack_a[0]);
	printf("stack_a[1]: %d\n", stacks->stack_a[1]);
	printf("stack_a[2]: %d\n", stacks->stack_a[2]);

	printf("auto\n");

	while (i < stacks->len_a)
	{
		printf("stack_a[%d]: %d\n", i, stacks->stack_a[i]);
		i++;
	}
	write(1, "a\n", 2);
	max = find_maxx(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != max)
		rotate_a(stacks);
	write(1, "b\n", 2);
	push_a(stacks);
	printf("---fine---\n");
}

// void	solve_five(t_stack stacks)
// {

// }
