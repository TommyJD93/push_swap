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

void	flag_manager(t_stack *stacks)
{
	int	max;
	int	i;
	int	j;

	i = stacks->len_lis;
	while (--i > -1)
	{
		
	}

}

int	_lis(int *arr, int len, int *lis, int *slave)
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
				{
					lis[i] = max;
					slave[j] = 0;
				}
				else
				{
					// printf("1+lis[j]\n");
					slave[j] = 1;
					// printf("slave[%d]: %d\n", j, slave[j]);
					lis[i] = 1 + lis[j];
				}
			}
			j++;
		}
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
	stacks->slave = allocation_helper(stacks->len_lis, 0);

	max = _lis(stacks->stack_a, stacks->len_a, stacks->lis, stacks->slave);
	// printf("flagged[0]: %d\n", flagged[0]);
	printf("----flagged----\n");
	i = -1;
	while (++i < stacks->len_lis)
		printf("%d\n", stacks->slave[i]);
	flag_manager(stacks);
	return (max);
}