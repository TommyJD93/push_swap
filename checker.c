/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:14 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/21 10:20:00 by tterribi         ###   ########.fr       */
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
				printf("ERROR: invalid\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	*dup_check_helper(t_stack *stacks)
{
	int *tmp;
	int	i;

	tmp = allocation_helper(stacks->len_a, 0);
	i = -1;
	while (++i < stacks->len_a)
		tmp[i] = stacks->stack_a[i];
	return (tmp);
}

void	duplicates_check(t_stack *stacks)
{
	int		*tmp;
	int		i;
	int		j;
	int		check;

	tmp = dup_check_helper(stacks);
	i = -1;
	while (++i < stacks->len_a)
	{
		j = -1;
		check = 0;
		while (++j < stacks->len_a)
		{
			if (stacks->stack_a[j] == tmp[i])
				check++;
		}
		if (check > 1)
		{
			printf("ERROR: duplicated numbers found\n");
			exit(0);
		}
	}
}