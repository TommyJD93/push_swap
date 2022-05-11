/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:55 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/11 17:10:21 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocation_helper(t_stack *stacks)
{
	int i;

	stacks->stack_a = (int *)malloc(sizeof(int *) * stacks->stack_len + 1);
	if (!stacks->stack_a)
	{
		printf("allocation gone wrong");
		return ;
	}
	i = -1;
	while (i < stacks->stack_len)
		stacks->stack_a[i++] = 0;
}

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
	int j;
	
	//int	*arr;

	i = 0;
	stacks->stack_len = stack_len_calc(input);
	printf("stack len: %d\n", stacks->stack_len);
	allocation_helper(stacks);
	//stacks->stack_a = (int *)malloc(sizeof(int *) * stacks->stack_len + 1);
	if (!stacks->stack_a)
	{
		printf("stack allocation gone wrong");
		exit(0);
	}
	j = 1;
//	checker();
	if (is_in_strings(' ',input[1]))
		string_manager(stacks->stack_a, input[1]);
	else
	{
		while (i < stacks->stack_len)
		{
			stacks->stack_a[i] = ft_atoi(input[i + 1]);
			i++;
		}
	}
	write(1, "f\n", 2);
	//stacks->stack_a[stacks->stack_len + 1] = '\0';
	write(1, "z\n", 2);
}
