/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:37:06 by ffrau             #+#    #+#             */
/*   Updated: 2022/09/19 17:36:56 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack *stack, int can_write)
{
	int	tmp;

	if (stack->len_b >= 2)
	{
		tmp = stack->stack_b[1];
		stack->stack_b[1] = stack->stack_b[0];
		stack->stack_b[0] = tmp;
	}
	if (can_write)
		ft_printf("sb\n");
}

void	rotate_b(t_stack *stack, int can_write)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->len_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->len_b - 1] = tmp;
	if (can_write)
		ft_printf("rb\n");
}

void	reverse_rotate_b(t_stack *stack, int can_write)
{
	int	tmp;
	int	i;

	i = stack->len_b - 1;
	tmp = stack->stack_b[stack->len_b - 1];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (can_write)
		ft_printf("rrb\n");
}

void	push_b_helper(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
}

void	push_b(t_stack *stack, int can_write)
{
	int	*tmp;
	int	i;

	i = 0;
	if (!(stack->len_a))
		return ;
	tmp = malloc(stack->len_b * sizeof(int));
	while (i < stack->len_b)
	{
		tmp[i] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[0] = stack->stack_a[0];
	stack->len_b++;
	push_b_helper(stack, tmp);
	free(tmp);
	stack->len_a--;
	if (can_write)
		ft_printf("pb\n");
}
