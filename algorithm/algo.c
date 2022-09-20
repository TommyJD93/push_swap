/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:17:20 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/20 11:07:37 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lis_flag(t_stack *stacks, int max)
{
	int	i;
	int	j;
	int	*arr;

	arr = allocation_helper(stacks->len_lis, 0);
	i = 0;
	j = 0;
	while (stacks->lis[i] != max)
		i++;
	while (i >= 0)
	{
		if (stacks->lis[i] == (max - j))
		{
			arr[i] = 1;
			j++;
		}
		i--;
	}
	stacks->lis = arr;
}

int	lis(t_stack *stacks)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (i < stacks->len_a)
	{
		j = i;
		while (j < stacks->len_a)
		{
			if (stacks->stack_a[i] < stacks->stack_a[j]
				&& stacks->lis[i] == stacks->lis[j])
			{
				stacks->lis[j]++;
				if (stacks->lis[j] > max)
					max = stacks->lis[j];
			}
			j++;
		}
		i++;
	}
	max = find_max(stacks->lis, stacks->len_lis);
	return (max);
}

void	lis_wrapper(t_stack *stacks)
{
	stacks->max = lis(stacks);
	lis_flag(stacks, stacks->max);
}
