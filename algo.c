/* ************************************************************************** */
/*                                                                      */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/08 15:43:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	lis_flagging()
// {
// 		while ()
// 		{
// 			/* code */
// 		}
// }

/*
i = (indice per scorrere l'array)
res = (risultato del precedente lis)
max_ref || max = ()
max_ending_here = (risultato finale)
*/

int	find_max(int *arr, int index)
{
	int	i;
	int	max;

	i = -1;
	max = arr[index];
	while (arr[++i])
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return(max);
}

int	_lis(int *arr, int len, int *lis)
{
	int	max;
	int	i;
	int	j;

	i = len;
	while (--i > -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] < arr[j])
			{
				max = find_max(lis, i);
				if (max > lis[j])
					lis[i] = max;
				else
					lis[i] = 1 + lis[j];
			}
			j++;
		}
	}
	max = find_max(lis, i);
	return(max);
}

void	flag_manager(t_stack stacks)
{
	int	max;
	int	i;

	max = stacks.lis[0];
	printf("%d\n", max);
	i = 0;
	while (stacks.lis[i])
	{
		if (stacks.lis[i] <= max)
		{
			max--;
			stacks.lis[i] = 1;
		}
		else
		{
			stacks.lis[i] = 0;
		}
		i++;
	}
}

// int	_lis(int *arr, int arr_len, int *max_ref, int *lis)
// {
// 	int	i;
// 	int	res;
// 	int	max_ending_here;

// 	i = 0;
// 	res = 1;
// 	max_ending_here = 1;
// 	if (arr_len == 1)
// 		return 1;
// 	while(i < arr_len)
// 	{
// 		res = _lis(arr, i, max_ref, lis);
// 		if (arr[i - 1] < arr[arr_len - 1]
// 			&& res + 1 > max_ending_here)
// 		{
// 			max_ending_here = res + 1;
// 			lis[i] = 1;
// 			// printf("num: %d\n", arr[i - 1]);
// 			// printf("num1: %d\n", arr[arr_len - 1]);
// 		}
// 		i++;
// 	}
// 	if (*max_ref < max_ending_here)
// 	*max_ref = max_ending_here;
// 	return (max_ending_here);
// }

int	lis(t_stack stacks)
{
	int max;

	max = _lis(stacks.stack_a, stacks.len_a, stacks.lis);
	flag_manager(stacks);
	return max;
}