/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:28:20 by ffrau             #+#    #+#             */
/*   Updated: 2022/09/19 17:40:40 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *stack, int can_write)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = stack->stack_a[1];
		stack->stack_a[1] = stack->stack_a[0];
		stack->stack_a[0] = tmp;
	}
	if (can_write)
		ft_printf("sa\n");
}

void	rotate_a(t_stack *stack, int can_write)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->len_a - 1] = tmp;
	if (can_write)
		ft_printf("ra\n");
}

void	reverse_rotate_a(t_stack *stack, int can_write)
{
	int	tmp;
	int	i;

	i = stack->len_a - 1;
	tmp = stack->stack_a[stack->len_a - 1];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (can_write)
		ft_printf("rra\n");
}

void	push_a_helper(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->stack_a[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
}

void	push_a(t_stack *stack, int can_write)
{
	int	*tmp;
	int	i;

	if (!(stack->len_b))
		return ;
	i = 0;
	tmp = malloc(stack->len_a * sizeof(int));
	while (i < stack->len_a)
	{
		tmp[i] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[0] = stack->stack_b[0];
	stack->len_a++;
	push_a_helper(stack, tmp);
	free (tmp);
	stack->len_b--;
	if (can_write)
		ft_printf("pa\n");
}
