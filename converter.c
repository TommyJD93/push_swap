/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:52:55 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/09 18:47:34 by tterribi         ###   ########.fr       */
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
	int	len;
	int *arr;
	int i = 0;

	len = stack_len_calc(input);
	arr = (int *)malloc(sizeof(int *) * len + 1);
	if (!arr)
	{
		printf("stack allocation gone wrong");
		exit(0);
	}
	if (is_in_strings(' ', input[1]))
	{
		string_manager(arr, input[1]);
	}
	
}
