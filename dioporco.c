/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioporco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:38:58 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/05 13:15:25 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *arr, int len)
{
	int	min;
	int	i;

	min = arr[0];
	i = 0;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

void	solve_three(t_stack *stacks)
{
	int	min;

	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks);
	push_b(stacks);
	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks);
	push_a(stacks);
}

void	solve_five(t_stack *stacks)
{
	int	min;
	int	len;
	int	i;

	min = find_min(stacks->stack_a, stacks->len_a);
	len = stacks->len_a;
	i = 0;
	while (stacks->len_a)
	{
		if (stacks->stack_a[0] == min)
		{
			push_b(stacks);
			min = find_min(stacks->stack_a, stacks->len_a);
		}
		rotate_a(stacks);
		i++;
	}
	while (stacks->len_a != len)
	{
		push_a(stacks);
		reverse_rotate_b(stacks);
	}
}
