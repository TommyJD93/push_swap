/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioporco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:38:58 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/06 12:37:35 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stack *stacks)
{
	int	min;

	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks);
	push_b(stacks);
	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		rotate_a(stacks);
	push_a(stacks);
}

void	solve_five(t_stack *stacks)
{
	int	tmp;

	tmp = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != tmp)
		ft_ra(stacks, 1);
	ft_pb(stacks, 1);
	tmp = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != tmp)
		ft_ra(stacks, 1);
	ft_pb(stacks, 1);
	solve_three(stacks);
	tmp = find_max(stacks->stack_b, 0);
	while (stacks->stack_b[0] != tmp)
		ft_rb(stacks, 1);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
}
