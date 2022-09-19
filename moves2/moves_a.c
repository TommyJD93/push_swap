/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:56:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 11:51:20 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stacks, int caga)
{
	int	tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
		if (caga == 1)
			write(1, "sa\n", ft_strlen("sa\n"));
	}
}

void	ft_pa(t_stack *stacks, int caga)
{
	int	i;

	if (stacks->len_b > 0)
	{
		i = stacks->len_a;
		while (i--)
			stacks->stack_a[i + 1] = stacks->stack_a[i];
		stacks->stack_a[0] = stacks->stack_b[0];
		stacks->len_a += 1;
		i = 1;
		while (i < stacks->len_b)
		{
			stacks->stack_b[i - 1] = stacks->stack_b[i];
			i++;
		}
		stacks->len_b -= 1;
		if (caga == 1)
			write(1, "pa\n", ft_strlen("pa\n"));
	}
}

void	ft_ra(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_a[0];
		i = 1;
		while (i < stacks->len_a)
		{
			stacks->stack_a[i - 1] = stacks->stack_a[i];
			i++;
		}
		stacks->stack_a[i - 1] = tmp;
		if (caga == 1)
			write(1, "ra\n", ft_strlen("ra\n"));
	}
}

void	ft_rra(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_a[stacks->len_a - 1];
		i = stacks->len_a - 1;
		while (i--)
			stacks->stack_a[i + 1] = stacks->stack_a[i];
		stacks->stack_a[0] = tmp;
		if (caga == 1)
			write(1, "rra\n", ft_strlen("rra\n"));
	}
}

void	ft_rrr(t_stack *stacks, int caga)
{
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (caga == 1)
		write(1, "rrr\n", ft_strlen("rrr\n")); 
}