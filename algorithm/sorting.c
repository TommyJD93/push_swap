/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:51 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/20 11:06:27 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_flags(t_stack *stacks)
{
	int	i;

	i = 0;
	while (stacks->len_a != stacks->max)
	{
		if (stacks->lis[i] == 1)
			rotate_a(stacks, 1);
		else
			push_b(stacks, 1);
		i++;
	}
}

void	solve_three(t_stack *stacks)
{
	int	min;

	min = find_min(stacks);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks, 1);
	push_b(stacks, 1);
	min = find_min(stacks);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks, 1);
	push_a(stacks, 1);
}

void	solve_five(t_stack *stacks)
{
	int	tmp;

	tmp = find_min(stacks);
	while (stacks->stack_a[0] != tmp)
		rotate_a(stacks, 1);
	push_b(stacks, 1);
	tmp = find_min(stacks);
	while (stacks->stack_a[0] != tmp)
		rotate_a(stacks, 1);
	push_b(stacks, 1);
	solve_three(stacks);
	tmp = find_max(stacks->stack_b, 0);
	while (stacks->stack_b[0] != tmp)
		rotate_b(stacks, 1);
	push_a(stacks, 1);
	push_a(stacks, 1);
}

void	algo_helper(t_stack *stacks)
{
	int	i;
	int	j;

	i = num_to_move(stacks);
	j = find_next_elem(stacks, i);
	if (cases(stacks, i) == 1)
	{
		if (i <= j)
			case_one_a(stacks, i, j);
		else
			case_one_b(stacks, i, j);
	}
	else if (cases(stacks, i) == 4)
	{
		if ((stacks->len_b - i) < (stacks->len_a - j))
			case_four_a(stacks, i, j);
		else
			case_four_b(stacks, i, j);
	}
	else if (cases(stacks, i) == 2)
		case_two_a(stacks, i, j);
	else
		case_two_b(stacks, i, j);
	push_a(stacks, 1);
}

void	solve(t_stack *stacks)
{
	lis_wrapper(stacks);
	move_flags(stacks);
	while (stacks->len_b != 0)
		algo_helper(stacks);
	order_manager(stacks);
}
