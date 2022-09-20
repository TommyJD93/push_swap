/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:36:59 by ffrau             #+#    #+#             */
/*   Updated: 2022/09/20 11:01:04 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_ab(t_stack *stack, int can_write)
{
	reverse_rotate_b(stack, false);
	reverse_rotate_a(stack, false);
	if (can_write)
		ft_printf("rrr\n");
}

void	rotate_ab(t_stack *stack, int can_write)
{
	rotate_a(stack, false);
	rotate_b(stack, false);
	if (can_write)
		ft_printf("rr\n");
}

void	swap_ab(t_stack *stack, int can_write)
{
	swap_b(stack, false);
	swap_a(stack, false);
	if (can_write)
		ft_printf("ss\n");
}

void	case_four_b(t_stack *stack, int i, int j)
{
	while (stack->len_a - j > 0)
	{
		reverse_rotate_ab(stack, true);
		i++;
		j++;
	}
	while (stack->len_b - i > 0)
	{
		reverse_rotate_b(stack, true);
		j++;
		i++;
	}
}
