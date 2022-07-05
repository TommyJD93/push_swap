/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:55:56 by tterribi          #+#    #+#             */
/*   Updated: 2022/07/05 13:17:25 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack *stacks)
{
	int	tmp;

	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[0] = tmp;
}

void	push_manager_b(t_stack *stacks, int *temp)
{
	int	i;

	i = 0;
	while (i < stacks->len_b)
	{
		stacks->stack_b[i + 1] = temp[i];
		i++;
	}
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
}

void	push_b(t_stack *stacks)
{
	int	*temp;
	int	i;

	i = 0;
	if (!(stacks->stack_a))
		exit(0);
	temp = malloc(stacks->len_b * sizeof(int));
	while (i < stacks->len_b)
	{
		temp[i] = stacks->stack_b[i];
		i++;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->len_b++;
	push_manager_b(stacks, temp);
	free(temp);
	stacks->len_a--;
	ft_printf("pb\n");
}

void	rotate_b(t_stack *stacks)
{
	int	*arr;
	int	i;
	int	len;

	len = stacks->len_b;
	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit(0);
	while (stacks->stack_b[len])
	{
		arr[0] = stacks->stack_b[len - 1];
		len--;
		i++;
	}
	arr[i] = '\0';
	free(stacks->stack_b);
	stacks->stack_b = arr;
}

void	reverse_rotate_b(t_stack *stacks)
{
	int	*arr;
	int	i;
	int	len;

	len = stacks->len_b;
	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit(0);
	while (i < len - 1)
	{
		arr[i] = stacks->stack_b[i + 1];
		i++;
	}
	arr[i] = '\0';
	free(stacks->stack_b);
	stacks->stack_b = arr;
	ft_printf("rrb\n");
}