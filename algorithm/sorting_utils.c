/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:02:43 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 18:21:54 by tterribi         ###   ########.fr       */
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