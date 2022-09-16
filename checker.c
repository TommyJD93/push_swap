/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:01:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 17:16:53 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	*dup_check_helper(t_stack *stacks)
{
	int	*tmp;
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
			error(stacks);
	}
}

void	input_checker_wrapper(int argc, char**argv, t_stack *stacks)
{
	if (argc < 2)
		exit(0);
	input_checker(argv);
	converter(argv, stacks);
	duplicates_check(stacks);
}

void	final_checker(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a - 1)
	{
		if (!(stacks->stack_a[i] < stacks->stack_a[i + 1]))
			error(stacks);
		i++;
	}
	terminate(stacks);
}
