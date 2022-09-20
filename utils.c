/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:54:12 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/20 11:08:39 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*allocation_helper(int len, int init_val)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int *) * (len + 1));
	if (!arr)
	{
		printf("Error\n");
		exit (0);
	}
	i = -1;
	while (i < len)
		arr[i++] = init_val;
	arr[i] = '\0';
	return (arr);
}

void	terminate(t_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->lis);
	exit(0);
}

void	error(t_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->lis);
	exit(0);
}

int	find_min(t_stack *stacks)
{
	int	min;
	int	i;

	i = -1;
	min = stacks->stack_a[0];
	while (++i < stacks->len_a)
	{
		if (stacks->stack_a[i] < min)
			min = stacks->stack_a[i];
	}
	return (min);
}

int	find_max(int *arr, int len)
{
	int	max;
	int	i;

	i = -1;
	max = arr[0];
	while (++i < len)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}
