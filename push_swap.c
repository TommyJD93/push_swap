/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/25 13:22:08 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int	i = -1;

	if (argc < 2)
		return (1);
	converter(argv, &stacks);
	//---------test mosse---------//
	// printf("----napoli----\n");
	// while (stacks.stack_a[++i])
	// 	printf("%d\n", stacks.stack_a[i]);
	// swap_a(&stacks);
	// printf("----caserta----\n");
	// i = -1;
	// while (stacks.stack_a[++i])
	// 	printf("%d\n", stacks.stack_a[i]);

	//---------test algo---------//
	printf("----napoli----\n");
	while (stacks.stack_a[++i])
		printf("%d\n", stacks.stack_a[i]);
	wrapper(&stacks);
	// printf("len: %d\n", stacks.len_a);
	// while (i < stacks.len_a)
	// {
	// 	printf("%d\n", stacks.stack_a[i]);
	// 	i++;
	// }
}

	// printf("----argv structure----\n");
	// int j;
	// while (argv[i])
	// {
	// 	j = 0;
	// 	printf("argv[%d][%d]: ", i, j);
	// 	while (argv[i][j])
	// 	{
	// 		printf("%c", argv[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }