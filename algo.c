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

int	_lis(int *arr, int arr_len, int *max_ref, int *lis)
{
	int	i;
	int	res;
	int	max_ending_here;

	i = 0;
	res = 1;
	max_ending_here = 1;
	if (arr_len == 1)
		return 1;
	while(i < arr_len)
	{
		res = _lis(arr, i, max_ref, lis);
		if (arr[i] < arr[arr_len]
		&& res + 1 > max_ending_here)
		{
			max_ending_here = res + 1;
			lis[i] = 1;
			// printf("num: %d\n", arr[i - 1]);
			// printf("num1: %d\n", arr[arr_len - 1]);
		}
		i++;
	}
	if (*max_ref < max_ending_here)
	*max_ref = max_ending_here;

	return (max_ending_here);
}

int lis(int *arr, int arr_len, int *lis)
{
	int max;

	max = 1;

	_lis(arr, arr_len, &max, lis);
	return max;
}