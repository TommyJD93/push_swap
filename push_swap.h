/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:31:49 by tterribi          #+#    #+#             */
/*   Updated: 2022/09/19 08:40:00 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*lis;
	int	len_a;
	int	len_b;
	int	len_lis;
}	t_stack;

//checker
void	input_checker_wrapper(int argc, char**argv, t_stack *stacks);
void	final_checker(t_stack *stacks);

//converter
void	converter(char **input, t_stack *stacks);

//utils
int		*allocation_helper(int len, int init_val);
void	terminate(t_stack *stacks);
void	error(t_stack *stacks);
int		find_min(t_stack *stacks);
int		find_max(int *arr, int len);

// Algorithm
void	lis_wrapper(t_stack *stacks);
void	solve_three(t_stack *stacks);
void	solve_five(t_stack *stacks);
void	solve(t_stack *stacks);

// Algorithm utils
void move_flags(t_stack *stacks);
bool	b_gretaer(t_stack *stacks, int i);
bool	b_smaller(t_stack *stacks, int i);
int		find_pos_max(t_stack *stacks);
int		find_pos_min(t_stack *stacks);
int		cases(t_stack *stacks, int i);
int		find_next_elem(t_stack *stacks, int i);
int		moves_counter(t_stack *stacks, int i, int j);
int		num_to_move(t_stack *stacks);
void	order_manager(t_stack *stacks);

// moves
void ft_sa(t_stack *stacks, int caga);
void	ft_sb(t_stack *stacks, int caga);
void	ft_pa(t_stack *stacks, int caga);
void	ft_pb(t_stack *stacks, int caga);
void	ft_ra(t_stack *stacks, int caga);
void	ft_rb(t_stack *stacks, int caga);
void	ft_rra(t_stack *stacks, int caga);
void	ft_rrb(t_stack *stacks, int caga);
void	ft_rr(t_stack *stacks, int caga);
void	ft_rrr(t_stack *stacks, int caga);
void	case_zero_a(t_stack *stacks, int i, int j);
void	case_zero_b(t_stack *stacks, int i, int j);
void	case_one_a(t_stack *stacks, int i, int j);
void	case_one_b(t_stack *stacks, int i, int j);
void	case_three_a(t_stack *stacks, int i, int j);
void	case_three_b(t_stack *stacks, int i, int j);

#endif