/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:56 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/05 14:21:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack *stacks)
{
	int	tmp;

	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[0] = tmp;
}

void	push_manager_b(t_stack *stacks, int *temp)
{
	int	i;

	i = 0;
	while (i < stacks->len_b)
	{
		stacks->stack_b[i + 1] = temp[i];
		i++;
	}
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
}

void	push_b(t_stack *stacks)
{
	int	*temp;
	int	i;

	i = 0;
	if (!(stacks->stack_a))
		exit(0);
	temp = malloc(stacks->len_b * sizeof(int));
	while (i < stacks->len_b)
	{
		temp[i] = stacks->stack_b[i];
		i++;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->len_b++;
	push_manager_b(stacks, temp);
	free(temp);
	stacks->len_a--;
	// ft_printf("pb\n");
}

void	rotate_b(t_stack *stacks)
{
	int	i;
	int temp;

	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->len_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->len_a - 1] = temp;
	// write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack *stacks)
{
	int	tmp;
	int	i;

	i = stacks->len_b - 1;
	tmp = stacks->stack_b[stacks->len_b - 1];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = tmp;
}