/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:35:47 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/06 12:37:18 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*allocation_helper(int len)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int *) * (len + 1));
	if (!arr)
	{
		printf("allocation gone wrong");
		exit (0);
	}
	i = -1;
	while (i < len)
		arr[i++] = 1;
	arr[i] = '\0';
	// int j = -1;
	// while (arr[++j])
	// 	printf("%d\n", arr[j]);
	return (arr);
}

int	find_min(int *arr, int len)
{
	int	min;
	int	i;

	min = arr[0];
	i = 0;
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

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