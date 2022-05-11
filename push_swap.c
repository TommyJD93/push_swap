/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:02 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/11 11:41:23 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int i = 0;

	if (argc < 2)
		return (1);
	converter(argv, &stacks);
	while (i < stacks.stack_len)
	{
		printf("%d\n", stacks.stack_a[i]);
		i++;
	}
}
