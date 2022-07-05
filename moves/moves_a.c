/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:56:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/05 11:45:11 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *stacks)
{
	int	tmp;

	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[0] = tmp;
}

void	push_manager_a(t_stack *stacks, int *temp)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		stacks->stack_a[i + 1] = temp[i];
		i++;
	}
	i = 0;
	while (i < stacks->len_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
}

void	push_a(t_stack *stacks)
{
	int	*temp;
	int	i;

	i = 0;
	if (!(stacks->stack_b))
		exit(0);
	temp = malloc(stacks->len_a * sizeof(int));
	while (i < stacks->len_a)
	{
		temp[i] = stacks->stack_a[i];
		i++;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->len_a++;
	push_manager_a(stacks, temp);
	free(temp);
	stacks->len_b--;
	ft_printf("pa\n");
}

void	rotate_a(t_stack *stacks)
{
	int	i;
	int temp;

	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->len_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->len_a - 1] = temp;
	write(1, "ra\n", 3);
}

// void	reverse_rotate_a(t_stack *stacks)
// {
// 	int	*arr;
// 	int	i;
// 	int	len;

// 	len = stacks->len_a;
// 	i = 0;
// 	arr = malloc(sizeof(int) * len);
// 	if (!arr)
// 		exit(0);
// 	while (i < len - 1)
// 	{
// 		arr[i] = stacks->stack_a[i + 1];
// 		i++;
// 	}
// 	arr[i] = '\0';
// 	free(stacks->stack_a);
// 	stacks->stack_a = arr;
// }
