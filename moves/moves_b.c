/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:56 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 18:14:31 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack *stacks, int caga)
{
	int	tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
		if (caga == 1)
			write(1, "sa\n", ft_strlen("sb\n"));
	}
}


void	ft_pb(t_stack *stacks, int caga)
{
	int	i;

	if (stacks->len_a > 0)
	{
		i = stacks->len_b;
		while (i--)
			stacks->stack_b[i + 1] = stacks->stack_b[i];
		stacks->stack_b[0] = stacks->stack_a[0];
		stacks->len_b += 1;
		i = 1;
		while (i < stacks->len_a)
		{
			stacks->stack_a[i - 1] = stacks->stack_a[i];
			i++;
		}
		stacks->len_a -= 1;
		if (caga == 1)
			write(1, "pb\n", ft_strlen("pb\n"));
	}
}

void	ft_rb(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_b > 1)
	{
		tmp = stacks->stack_b[0];
		i = 1;
		while (i < stacks->len_b)
		{
			stacks->stack_b[i - 1] = stacks->stack_b[i];
			i++;
		}
		stacks->stack_b[i - 1] = tmp;
		if (caga == 1)
			write(1, "rb\n", ft_strlen("rb\n"));
	}
}

void	ft_rr(t_stack *stacks, int caga)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (caga == 1)
		write(1, "ra\n", ft_strlen("rr\n")); // da cambiare in rr ma al visualizer non piaceva
}

void	ft_rrb(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_b > 1)
	{
		tmp = stacks->stack_b[stacks->len_b - 1];
		i = stacks->len_b - 1;
		while (i--)
			stacks->stack_b[i + 1] = stacks->stack_b[i];
		stacks->stack_b[0] = tmp;
		if (caga == 1)
			write(1, "rrb\n", ft_strlen("rrb\n"));
	}
}