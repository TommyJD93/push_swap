/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:14 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/06 13:01:45 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_checker(t_stack stacks)
{
	int	i;

	i = 0;
	while (i < stacks.len_a - 1)
	{
		if (!(stacks.stack_a[i] < stacks.stack_a[i + 1]))
		{
			printf("sorting failed :(");
			exit(0);
		}
		i++;
	}
}

void	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((argv[i][j] < 48) || (argv[i][j] > 57))
			{
				printf("input invalido :(");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	duplicates_check(t_stack *stacks)
{
	int		*tmp;
	int		i;
	int		j;
	bool	check;

	tmp = allocation_helper(stacks->len_a);
	i = -1;
	while (++i < stacks->len_a)
		tmp[i] = stacks->stack_a[i];
	i = 0;
	while (i < stacks->len_a)
	{
		j = 0;
		while (j < stacks->len_a)
		{
			if (stacks->stack_a[j] == tmp)
				check = 1;
		}
		if (check == 0)
	}

}