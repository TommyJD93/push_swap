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

int	_lis(int *arr, int n, int *max_ref, int *lis)
{
	int	i;
	int	res;
	int	max_ending_here;

	i = 1;
	max_ending_here = 1;
	if (n == 1)
		return 1;
	while(i < n)
	{
		res = _lis(arr, i, max_ref, lis);
		if (arr[i - 1] < arr[n - 1]
		&& res + 1 > max_ending_here)
		{
			max_ending_here = res + 1;

		}
		i++;
	}
	if (*max_ref < max_ending_here)
	*max_ref = max_ending_here;

	return (max_ending_here);
}

int lis(int *arr, int n, int *lis)
{
	int max;

	max = 1;

	_lis(arr, n, &max, lis);
	return max;
}