/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:16 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/16 18:29:54 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
}	t_stack;

//converter
int		stack_len_calc(char **matrix);
void	converter(char **input, t_stack *stacks);
void	string_manager(int *arr, char *string);
void	allocation_helper(t_stack *stacks, int len);

//moves
void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);
void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	reverse_rotate_a(t_stack *stacks);
void	reverse_rotate_b(t_stack *stacks);
#endif