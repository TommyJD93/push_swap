/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:54:12 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 17:14:27 by tterribi         ###   ########.fr       */
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
