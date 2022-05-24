/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:33:10 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/23 19:32:39 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack *stacks)
{
	//	allocation_helper(stacks->lis, stacks->len_a);
}

int	fis(int *arr, int *max, int n, int	*lis)
{
	int	out;
	int	ending;
	int	i;

	ending = 1;
	out = 1;
	if (n == 1)
		return (1);
	i = 1;
	while (i < n)
	{
		out = fis(arr, max, i, lis);
		if (arr[i - 1] < arr[n - 1]
			&& out + 1 > ending)
		{
			ending = out + 1;
			lis[i + 1] += 1;
		}
		i++;
	}
	if (*max < ending)
		*max = ending;
	return (ending);
}

int	wrapper(int *arr, int len)
{
	//int	len;
	int	max;
	int *lis;

	lis = allocation_helper(lis, len);
	int i = -1;
	while (lis[++i])
		printf("lis[%d]: %d", i, lis[i]);
	max = 1;
	//len = stacks->len_a;
	fis(arr, &max, len, lis);
	i = -1;
	write(1,"diocane\n", 8);
	while (lis[++i])
		printf("lis[%d]: %d", i, lis[i]);
	return max;
}

int main(void)
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	printf("lis: %d\n", wrapper(arr, 8));
}