/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:31:53 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/20 11:07:52 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	input_checker_wrapper(argc, argv, &stacks);
	if (stacks.len_a == 3)
		solve_three(&stacks);
	else if (stacks.len_a == 5)
		solve_five(&stacks);
	solve(&stacks);
	final_checker(&stacks);
}
