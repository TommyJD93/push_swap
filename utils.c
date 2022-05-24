/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:35:47 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/23 19:35:27 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int	*allocation_helper(int *arr, int len)
{
	int	i;

	arr = (int *)malloc(sizeof(int *) * len + 1);
	if (!arr)
	{
		printf("allocation gone wrong");
		exit (0);
	}
	i = -1;
	while (i < len)
		arr[i++] = 0;
	arr[i] = '\0';
	int j = -1;
	while (arr[++j])
		printf("%d\n", arr[j]);
	return (arr);
}
