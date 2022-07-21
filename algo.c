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

int _lis(int *arr, int len, int *lis)
{
	int	max;
	int	i;
	int	j;
	int	curr_max;
	int	*slave;
	// int	*master;

	slave = (int *)malloc(sizeof(int *) * len);

	if (!(slave))
	{
		printf("error while allocating master and slave\n");
		exit(0);
	}
	i = len;
	while (--i > -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
			{
				curr_max = find_max(slave, i);
				if (curr_max > slave[j])
				{
					// lis[i] = max;
					slave[i] = curr_max;
				}
				else
				{
					// lis[i] = 1 + lis[j];
					slave[i] = 1 + slave[j];
				}
			}
			j++;
		}
		if (curr_max > max)
		{
			max = curr_max;
			ft_memcpy(lis, slave, len);
		}
	}
	max = find_max(lis, i);
	return (max);
}

int	lis(t_stack stacks)
{
	int	max;
	int	i;

	max = _lis(stacks.stack_a, stacks.len_a, stacks.lis);
	printf("----lis----\n");
	i = -1;
	while (++i < stacks.len_lis)
		printf("%d\n", stacks.lis[i]);
	//flag_manager(stacks);
	return max;
}