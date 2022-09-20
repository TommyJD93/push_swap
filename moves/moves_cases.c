/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:25:25 by ffrau             #+#    #+#             */
/*   Updated: 2022/09/20 11:01:46 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_a(t_stack *stack, int i, int j)
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

void	case_two_b(t_stack *stack, int i, int j)
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

void	case_one_a(t_stack *stack, int i, int j)
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

void	case_one_b(t_stack *stack, int i, int j)
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

void	case_four_a(t_stack *stack, int i, int j)
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
