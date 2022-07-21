/* ************************************************************************** */
/*                                                                      */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/08 15:43:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_manager(t_stack stacks)
{
	int	max;
	int	i;

	printf("-----g-----\n");
	i = -1;
	while (++i < stacks.len_lis)
		printf("%d\n", stacks.lis[i]);

	max = stacks.lis[0];
	i = 0;
	while (stacks.lis[i])
	{
		if (stacks.lis[i] <= max)
		{
			max--;
			stacks.lis[i] = 1;
		}
		else
		{
			stacks.lis[i] = 0;
		}
		i++;
	}
}

void	flag_managerr(t_stack *stacks)
{
	int	min;
	int	i;

	min = find_min(stacks->lis, stacks->len_lis);
	i = stacks->len_lis;
	while (i >= 0)
	{
		if (stacks->lis[i] == min)
		{
			stacks->lis[i] = 1;
			min++;
		}
		else
		{
			stacks->lis[i] = 0;
		}
		i--;
	}
	printf("-----h-----\n");
	i = -1;
	while (++i < stacks->len_lis)
		printf("%d\n", stacks->lis[i]);
}

int	_lis(int *arr, int len, int *lis)
{
	int	max;
	int	i;
	int	j;

	i = len;
	max = 0;
	while (--i > -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
			{
				max = find_max(lis, i);
				if (max > lis[j])
					lis[i] = max;
				else
					lis[i] = 1 + lis[j];
			}
			j++;
		}
	}
	max = find_max(lis, i);
	return(max);
}


int	lis(t_stack *stacks)
{
	int max;
	int i;

	max = _lis(stacks->stack_a, stacks->len_a, stacks->lis);
	printf("----lis----\n");
	i = -1;
	while (++i < stacks->len_lis)
		printf("%d\n", stacks->lis[i]);
	flag_managerr(stacks);
	return max;
}