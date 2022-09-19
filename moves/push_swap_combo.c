/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_combo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:25:25 by ffrau             #+#    #+#             */
/*   Updated: 2022/09/19 17:37:22 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_rrb(t_stack *stack, int i, int j)
{
	while (j > 0)
	{
		rotate_a(stack, true);
		j--;
	}
	while (stack->len_b - i > 0)
	{
		reverse_rotate_b(stack, true);
		i++;
	}
}

void	rb_rra(t_stack *stack, int i, int j)
{
	while (i > 0)
	{
		rotate_b(stack, true);
		i--;
	}
	while (stack->len_a - j > 0)
	{
		reverse_rotate_a(stack, true);
		j++;
	}
}

void	rab_ra(t_stack *stack, int i, int j) //1
{
	while (i > 0)
	{
		rotate_ab(stack, true);
		j--;
		i--;
	}
	while (j > 0)
	{
		rotate_a(stack, true);
		j--;
	}
}

void	rab_rb(t_stack *stack, int i, int j) //2
{
	while (j > 0)
	{
		rotate_ab(stack, true);
		j--;
		i--;
	}
	while (i > 0)
	{
		rotate_b(stack, true);
		i--;
	}
}

void	rrab_rra(t_stack *stack, int i, int j) //3rrab_rra
{
	while (stack->len_b - i > 0)
	{
		reverse_rotate_ab(stack, true);
		i++;
		j++;
	}
	while (stack->len_a - j > 0)
	{
		reverse_rotate_a(stack, true);
		j++;
	}
}
