/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:35:37 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 18:18:37 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_zero_a(t_stack *stacks, int i, int j) // rr_ra | rab_ra
{
	while (i > 0)
	{
		ft_rr(stacks, 1);
		j--;
		i--;
	}
	while (j > 0)
	{
		ft_ra(stacks, 1);
		j--;
	}
}

void	case_zero_b(t_stack *stacks, int i, int j) // rr_rb | rab_rb
{
	while (j > 0)
	{
		ft_rr(stacks, 1);
		j--;
		i--;
	}
	while (i > 0)
	{
		ft_rb(stacks, 1);
		i--;
	}
}

void	case_one_a(t_stack *stacks, int i, int j) //ra_rrb
{
	while (j > 0)
	{
		ft_ra(stacks, 1);
		j--;
	}
	while (stacks->len_b - i > 0)
	{
		ft_rrb(stacks, 1);
		i++;
	}
}

void	case_one_b(t_stack *stacks, int i, int j) //rb_rra
{
	while (i > 0)
	{
		ft_rb(stacks, 1);
		i--;
	}
	while (stacks->len_a - j > 0)
	{
		ft_rra(stacks, 1);
		j++;
	}
}

void	case_three_a(t_stack *stacks, int i, int j) //rrr_rra | rrab_rra
{
	while (stacks->len_b - i > 0)
	{
		ft_rrr(stacks, 1);
		i++;
		j++;
	}
	while (stacks->len_a - j > 0)
	{
		ft_rra(stacks, 1);
		j++;
	}
}

void	case_three_b(t_stack *stacks, int i, int j) //rrr_rrb | rrab_rrb
{
	while (stacks->len_a - j > 0)
	{
		ft_rrr(stacks, 1);
		i++;
		j++;
	}
	while (stacks->len_b - i > 0)
	{
		ft_rrb(stacks, 1);
		j++;
		i++;
	}
}
