/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:14 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/06 10:14:39 by tterribi         ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	*arr;
// 	int	len;

// 	input_checker(argv);

// 	// i = 0;
// 	// len = 6;
// 	// arr = malloc(sizeof(int) * 6);
// 	// while (i < 6)
// 	// {
// 	// 	arr[i] = i + 1;
// 	// 	i++;
// 	// }
// 	// arr[3] = INT_MAX;
// 	// arr[i] = '\0';
// 	// printf("-------------\n");
// 	// i = -1;
// 	// while (arr[++i])
// 	// 	printf("%d\n", arr[i]);
// 	// i = 0;
// 	// while (i < len - 1)
// 	// {
// 	// 	if (!(arr[i] < arr[i + 1]))
// 	// 	{
// 	// 		printf("sorting fallito :(");
// 	// 		exit(0);
// 	// 	}
// 	// 	i++;
// 	// }
// }