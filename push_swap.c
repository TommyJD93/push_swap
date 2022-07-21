/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/21 15:09:28 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int	i = -1;
	int len;

	if (argc < 2)
		return (1);
	input_checker(argv);
	converter(argv, &stacks);
	duplicates_check(&stacks);
	stacks.stack_b = allocation_helper(1, 0);
	stacks.lis = allocation_helper(stacks.len_a, 1);
	stacks.len_lis = stacks.len_a;
	printf("len_lis: %d\n", stacks.len_lis);
	printf("len_stack-a: %d\n", stacks.len_a);
	if (stacks.len_a == 3)
		solve_three(&stacks);
	else if (stacks.len_a == 5)
		solve_five(&stacks);
	len = lis(&stacks);
	printf("len: %d\n", len);
	//flag_manager(&stacks);
	printf("----flagged final----\n");
	i = -1;
	while (++i < stacks.len_lis)
		printf("%d\n", stacks.lis[i]);

	printf("----stack_a----\n");
	i = -1;
	while (++i < stacks.len_a)
		printf("%d\n", stacks.stack_a[i]);
}
