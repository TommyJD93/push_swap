/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:02:43 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 18:21:54 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos_min(t_stack *stacks)
{
	int	i;
	int	pos;
	int	min;

	pos = 0;
	i = -1;
	min = stacks->stack_a[0];
	while (++i < stacks->len_a)
	{
		if (stacks->stack_a[i] < min)
		{
			min = stacks->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

int	find_pos_max(t_stack *stacks)
{
	int	i;
	int	pos;
	int	max;

	pos = 0;
	i = -1;
	max = stacks->stack_a[0];
	while (++i < stacks->len_a)
	{
		if (stacks->stack_a[i] > max)
		{
			max = stacks->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

bool	b_gretaer(t_stack *stacks, int i)
{
	int	j;

	j = -1;
	while (++j < stacks->len_a)
	{
		if (stacks->stack_b[i] < stacks->stack_a[j])
			return (false);
	}
	return (true);
}

bool	b_smaller(t_stack *stacks, int i)
{
	int	j;

	j = -1;
	while (++j < stacks->len_a)
	{
		if (stacks->stack_b[i] > stacks->stack_a[j])
			return (false);
	}
	return (true);
}

int	moves_counter(t_stack *stacks, int i, int j)
{
	int	moves;

	if (cases(stacks, i) == 0)
	{
		if (j > i)
			moves = j;
		else
			moves = i;
	}
	else if (cases(stacks, i) == 1)
		moves = (stacks->len_b - i) + j;
	else if (cases(stacks, i) == 2)
		moves = stacks->len_a - j + i - 1;
	else if ((stacks->len_a - j) > (stacks->len_b - i))
		moves = stacks->len_a - j;
	else
		moves = stacks->len_b - i;
	return (moves);
}
