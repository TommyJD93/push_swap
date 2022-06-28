/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:55 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/28 12:08:34 by tterribi         ###   ########.fr       */
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
	//int j;

	//int	*arr;

	i = 0;
	stacks->len_a = stack_len_calc(input);
	// printf("stack len: %d\n", stacks->len_a);
	stacks->stack_a = allocation_helper(stacks->len_a);
	//stacks->stack_a = (int *)malloc(sizeof(int *) * stacks->stack_len + 1);
	if (!stacks->stack_a)
	{
		printf("stack allocation gone wrong");
		exit(0);
	}
	// printf("diocane: %d\n", stacks->stack_a[0]);
	//j = 1;
//	checker();
	// ft_printf("len a = %d\n", stacks->len_a);
	if (is_in_strings(' ',input[1]))
	{
		string_manager(stacks->stack_a, input[1]);
	//	write(1, "a\n", 2);
	}
	else
	{
	//	write(1, "c\n", 2);
		// ft_printf("len a = %d\n", stacks->len_a);
		while (i < stacks->len_a)
		{
			stacks->stack_a[i] = ft_atoi(input[i + 1]);
			i++;
			// printf("%d\n", i);
		}
	}
}
