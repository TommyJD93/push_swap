/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:17:20 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/19 16:41:13 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lis_flag(t_stack *stacks, int max)
{
	// since we need an array composed just by 0 and 1
	// we'll need to take the LIS that we have right now
	// for example (1 2 2 3 4 4 4 5 6 6 7 7) and choose wich
	// element we will set to 0 and 1 to do so we'll create
	// another array(a sort of workbench) that will be initialized
	// at 0, at this point we''read the LIS backwards and each time
	// that we'll find that LIS[i] is equal to max - j we'll put a 1
	// in the other array at the same index. At this point we just
	// need to overwrite the LIS with the new array
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
	// first of all we want to read the stack A from left to right
	// and each time we see that an element is valid for an increasing
	// sequence we'll increase the respective cell of the LIS by 1
	/// in this way we'll obtain an array that should look something like this:
	// 1 2 2 3 4 4 4 5 6 6 7 7
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
