/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/06 15:51:30 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int	i = -1;
	// int len;

	if (argc < 2)
		return (1);
	input_checker(argv);
	converter(argv, &stacks);
	duplicates_check(&stacks);
	stacks.stack_b = allocation_helper(1);
	stacks.lis = allocation_helper(stacks.len_a);
	if (stacks.len_a == 3)
		solve_three(&stacks);
	else if (stacks.len_a == 5)
		solve_five(&stacks);
	// len = lis(stacks);
	printf("----result----\n");
	i = -1;
	while (++i < stacks.len_a)
		printf("%d\n", stacks.stack_a[i]);
}
