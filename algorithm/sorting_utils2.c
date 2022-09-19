/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:07:49 by marvin            #+#    #+#             */
/*   Updated: 2022/09/19 17:47:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_next_elem(t_stack *stacks, int i)
{
	int	j;

	if (b_gretaer(stacks, i))
		return (find_pos_max(stacks) + 1);
	if (b_smaller(stacks, i))
		return (find_pos_min(stacks));
	j = -1;
	while (++j < stacks->len_a)
	{
		if (stacks->stack_b[i] > stacks->stack_a[j] &&
			stacks->stack_b[i] < stacks->stack_a[j + 1])
			return (j + 1);
	}
	return (0);
}

// int	find_next_elem(t_stack *stacks, int i)
// {
// 	int	next;
// 	int	j;

// 	j = -1;
// 	next = find_max(stacks->stack_a, stacks->len_a);
// 	while (++j < stacks->len_a)
// 	{
// 		if (stacks->stack_a[j] > stacks->stack_b[i] && stacks->stack_a[j] < next)
// 			next = stacks->stack_a[j];
// 	}
// 	if (next == find_max(stacks->stack_a, stacks->len_a))
// 		return (find_pos_max(stacks));
// 	return (next);
// }

int	cases(t_stack *stacks, int i)
{
	while (i < stacks->len_b)
	{
		if (find_next_elem(stacks, i) < stacks->len_a / 2)
		{
			if (i <= stacks->len_b / 2)
				return (1);
			return (2);
		}
		else
		{
			if (i < stacks->len_b / 2)
				return (3);
			return (4);
		}
	}
	return (0);
}

int	num_to_move(t_stack *stacks)
{
	int	i;
	int	j;
	int	index;
	int	moves;
	int max_moves;

	i = 0;
	index = 0;
	max_moves = 999999;
	while (i < stacks->len_b)
	{
		j = find_next_elem(stacks, i);
		moves = moves_counter(stacks, i, j);
		if (moves < max_moves)
		{
			max_moves = moves;
			index = i;
		}
		i++;
	}
	return (index);
}

void	order_manager(t_stack *stacks)
{
	int min;

	min = find_min(stacks);
	while (stacks->stack_a[0] != min)
	{
		if (find_pos_min(stacks) <=  (stacks->len_a / 2))
			rotate_a(stacks, 1);
		else
			reverse_rotate_a(stacks, 1);
	}
}

