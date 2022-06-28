/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/28 17:01:25 by tterribi         ###   ########.fr       */
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
	converter(argv, &stacks);

	stacks.stack_b = allocation_helper(1);
	stacks.lis = allocation_helper(stacks.len_a);
	len = lis(stacks);

	printf("----solve_three----\n");
	solve_three(&stacks);
	i = -1;
	while (++i < 3)
		printf("%d\n", stacks.stack_a[i]);

}
