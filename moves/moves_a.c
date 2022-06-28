/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:56:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/28 08:31:19 by tterribi         ###   ########.fr       */
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

void	push_a(t_stack *stacks)
{
	int i;
	int *arr;

	arr = malloc(sizeof(int) * (stacks->len_a + 2));
	if (!arr)
		exit(0);
	arr[0] = stacks->stack_b[0];
	i = 1;
	while (stacks->stack_a[i])
	{
		arr[i] = stacks->stack_a[i - 1];
		i++;
	}
	arr[i] = '\0';
	free(stacks->stack_a);
	stacks->stack_a = arr;
}

int	*rotate_a(t_stack *stacks)
{
	int	*arr;
	int	i;
	int	len;

	len = stacks->len_a;
	arr = malloc(sizeof(int) * len - 1);
	if (!arr)
		exit(0);
	i = 0;
	while (len)
	{
		arr[i] = stacks->stack_a[len - 1];
		len--;
		i++;
	}
	return (arr);
}

void	reverse_rotate_a(t_stack *stacks)
{
	int	*arr;
	int	i;
	int	len;

	len = stacks->len_a;
	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit(0);
	while (i < len - 1)
	{
		arr[i] = stacks->stack_a[i + 1];
		i++;
	}
	arr[i] = '\0';
	free(stacks->stack_a);
	stacks->stack_a = arr;
}

int main(int argc, char **argv)
{
	t_stack stacks;
	int i = -1;
	int len;

	if (argc < 2)
		return (1);
	converter(argv, &stacks);
	while (stacks.stack_a[++i])
		printf("%d\n", stacks.stack_a[i]);
}