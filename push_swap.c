/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/09 09:15:05 by tterribi         ###   ########.fr       */
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


	//---------test algo---------//
	printf("----napoli----\n");
	while (stacks.stack_a[++i])
		printf("%d\n", stacks.stack_a[i]);

	stacks.lis = allocation_helper(stacks.len_a);
	len = lis(stacks.stack_a, stacks.len_a, stacks.lis);
	printf("lis len: %d\n", len);

	printf("----lis algo----\n");
	i = -1;
	while (stacks.stack_a[++i])
		printf("%d\n", stacks.lis[i]);




	// printf("----scampia----\n");
	// while (stacks.lis[++i])
	// 	printf("%d\n", stacks.lis[i]);
	// printf("len: %d\n", stacks.len_a);
	// while (i < stacks.len_a)
	// {
	// 	printf("%d\n", stacks.stack_a[i]);
	// 	i++;
	// }
}
