/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:37:45 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/16 17:16:30 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len_calc(char **matrix)
{
	int	cont;
	int	i;

	i = 0;
	cont = 0;
	while (matrix[i])
	{
		cont += get_word(matrix[i], ' ');
		i++;
	}
	return (cont - 1);
}

void	string_manager(int *arr, char *string)
{
	char	**mat;
	int		i;
	int		j;
	int		h;

	mat = ft_split(string, ' ');
	i = 0;
	h = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			arr[h] = ft_atoi(mat[i]);
			j++;
		}
		h++;
		i++;
	}
	arr[h] = '\0';
}

void	converter(char **input, t_stack *stacks)
{
	int	i;

	i = 0;
	stacks->len_a = stack_len_calc(input);
	stacks->len_lis = stacks->len_a;
	stacks->stack_a = allocation_helper(stacks->len_a, 0);
	stacks->stack_b = allocation_helper(stacks->len_a, 0);
	stacks->lis = allocation_helper(stacks->len_lis, 1);
	if (!stacks->stack_a)
		error(stacks);
	if (is_in_strings(' ', input[1]))
		string_manager(stacks->stack_a, input[1]);
	else
	{
		while (i < stacks->len_a)
		{
			stacks->stack_a[i] = ft_atoi(input[i + 1]);
			i++;
		}
	}
}
