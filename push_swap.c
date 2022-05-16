/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/16 13:10:34 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int	i = 0;

	if (argc < 2)
		return (1);
	converter(argv, &stacks);
	printf("----napoli----\n");
	printf("len: %d\n", stacks.len_a);
	while (i < stacks.len_a)
	{
		printf("%d\n", stacks.stack_a[i]);
		i++;
	}
}
