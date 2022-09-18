/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:08:51 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 18:24:44 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_flags(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->stack_a[0] == 1)
			ft_ra(stacks, 1);
		else
			ft_pb(stacks, 1);
		i++;
	}
}

void	solve_three(t_stack *stacks)
{
	int	min;

	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		ft_ra(stacks, 1);
	ft_pb(stacks, 1);
	min = find_min(stacks->stack_a, stacks->len_a);
	while (stacks->stack_a[0] != min)
		ft_ra(stacks, 1);
	ft_pa(stacks, 1);
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

void	algo_helper(t_stack *stacks)
{
	int	i;
	int	j;

	

}

void	solve(t_stack *stacks)
{
	lis_wrapper(stacks);
	move_flags(stacks);
	while (stacks->len_b != 0)
		algo_helper(stacks);

}