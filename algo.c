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

int	*flag_flush(int *arr, int len, int flag)
{
	int		i;
	bool	first;

	i = len;
	first = true;
	while (--i > 0)
	{
		// if (first && arr[i] == flag)
		// {
		// 	first = false;
		// 	continue ;
		// }
		// else if (arr[i] == flag)
		// {
			if (arr[i] == flag)
				arr[i] = 1;
			else
				arr[i] = 0;
		// }
	}
	printf("----flagged flush----\n");
	i = -1;
	while (++i < len)
		printf("%d\n", arr[i]);
	return (arr);
}

void	lis_manager(int *lis, int *slave, int len, int max)
{
	int i;
	int first;
	int k;


	first = 1;
	i = len;
	printf("max: %d\n", max);
	while (--i > -1)
	{
		if (slave[i] == max && first == 1)
		{
			lis[i] = 1;
			first = 0;
			continue ;
		}
		else if (first == 0)
		{
			lis[i] = 0;
		}
	}
	printf("----cane----\n");
	k = -1;
	while (++k < len)
		printf("%d\n", lis[k]);
}

int	_lis(int *arr, int len, int *lis, int *slave)
{
	int	max;
	int	i;
	int	j;
	int k = 0;

	i = len;
	max = 0;
	while (--i > -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
			{
				max = find_max(slave, i);
				if (max > slave[j])
					slave[i] = max;
				else
					slave[i] = 1 + slave[j];
			}
			j++;
		}
		printf("----dio----\n");
		k = -1;
		max = find_max(slave, i);
		while (++k < len)
			printf("%d\n", slave[k]);
		lis_manager(lis, slave, len, max);
	}
	max = find_max(lis, i);
	return (max);
}


// int _lis(int *arr, int len, int *lis)
// {
// 	int	max;
// 	int	i;
// 	int	j;
// 	int	curr_max;
// 	int	*slave;
// 	// int	*master;

// 	slave = (int *)malloc(sizeof(int *) * len);

// 	if (!(slave))
// 	{
// 		printf("error while allocating master and slave\n");
// 		exit(0);
// 	}
// 	i = len;
// 	while (--i > -1)
// 	{
// 		j = i + 1;
// 		while (j < len)
// 		{
// 			if (arr[i] < arr[j])
// 			{
// 				curr_max = find_max(slave, i);
// 				if (curr_max > slave[j])
// 				{
// 					// lis[i] = max;
// 					slave[i] = curr_max;
// 				}
// 				else
// 				{
// 					// lis[i] = 1 + lis[j];
// 					slave[i] = 1 + slave[j];
// 				}
// 			}
// 			j++;
// 		}
// 		// if (curr_max > max)
// 		// {
// 		// 	max = curr_max;
// 		// 	ft_memcpy(lis, slave, len);
// 		// }
// 	}
// 	max = find_max(lis, i);
// 	return (max);
// }

int	lis(t_stack *stacks)
{
	int	max;
	int	i;

	printf("len_lis: %d\n", stacks->len_lis);
	stacks->slave = allocation_helper(stacks->len_lis, 1);

	max = _lis(stacks->stack_a, stacks->len_a, stacks->lis, stacks->slave);
	// printf("flagged[0]: %d\n", flagged[0]);
	printf("----slave----\n");
	i = -1;
	while (++i < stacks->len_lis)
		printf("%d\n", stacks->slave[i]);
	// flag_manager(stacks);
	return (max);
}