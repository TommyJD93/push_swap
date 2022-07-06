#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_stack *stacks, int caga)
{
	if (stacks->len_a > 1)
	{
		ft_swap(stacks->stack_a, stacks->stack_a);
		if (caga == 1)
			write(1, "sa\n", ft_strlen("sa\n"));
	}
}

void	ft_sb(t_stack *stacks, int caga)
{
	if (stacks->len_b > 1)
	{
		ft_swap(stacks->stack_b, stacks->stack_b);
		if (caga == 1)
			write(1, "sb\n", ft_strlen("sb\n"));
	}
}

void	ft_ss(t_stack *stacks, int caga)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	if (caga == 1)
		write(1, "ss\n", ft_strlen("ss\n"));
}

void	ft_rra(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_a[stacks->len_a - 1];
		i = stacks->len_a - 1;
		while (i--)
			stacks->stack_a[i + 1] = stacks->stack_a[i];
		stacks->stack_a[0] = tmp;
		if (caga == 1)
			write(1, "rra\n", ft_strlen("rra\n"));
	}
}

void	ft_rrb(t_stack *stacks, int caga)
{
	int	i;
	int	tmp;

	if (stacks->len_b > 1)
	{
		tmp = stacks->stack_b[stacks->len_b - 1];
		i = stacks->len_b - 1;
		while (i--)
			stacks->stack_b[i + 1] = stacks->stack_b[i];
		stacks->stack_b[0] = tmp;
		if (caga == 1)
			write(1, "rrb\n", ft_strlen("rrb\n"));
	}
}

void	ft_rrr(t_stack *stacks, int caga)
{
	ft_rra(stacks, 0);
	ft_rrb(stacks, 0);
	if (caga == 1)
		write(1, "rrr\n", ft_strlen("rrr\n"));
}

void	ft_pa(t_stack *stacks, int caga)
{
	int	i;

	if (stacks->len_b > 0)
	{
		i = stacks->len_a;
		while (i--)
			stacks->stack_a[i + 1] = stacks->stack_a[i];
		stacks->stack_a[0] = stacks->stack_b[0];
		stacks->len_a += 1;
		i = 1;
		while (i < stacks->len_b)
		{
			stacks->stack_b[i - 1] = stacks->stack_b[i];
			i++;
		}
		stacks->len_b -= 1;
		if (caga == 1)
			write(1, "pa\n", ft_strlen("pa\n"));
	}
}

void	ft_pb(t_stack *stacks, int caga)
{
	int	i;

	if (stacks->len_a > 0)
	{
		i = stacks->len_b;
		while (i--)
			stacks->stack_b[i + 1] = stacks->stack_b[i];
		stacks->stack_b[0] = stacks->stack_a[0];
		stacks->len_b += 1;
		i = 1;
		while (i < stacks->len_a)
		{
			stacks->stack_a[i - 1] = stacks->stack_a[i];
			i++;
		}
		stacks->len_a -= 1;
		if (caga == 1)
			write(1, "pb\n", ft_strlen("pb\n"));
	}
}

void	ft_ra(t_stack *stacks, int caga)
{
	int		i;
	int		tmp;

	if (stacks->len_a > 1)
	{
		tmp = stacks->stack_a[0];
		i = 1;
		while (i < stacks->len_a)
		{
			stacks->stack_a[i - 1] = stacks->stack_a[i];
			i++;
		}
		stacks->stack_a[i - 1] = tmp;
		if (caga == 1)
			write(1, "ra\n", ft_strlen("ra\n"));
	}
}

void	ft_rb(t_stack *stacks, int caga)
{
	int		i;
	int		tmp;

	if (stacks->len_b > 1)
	{
		tmp = stacks->stack_b[0];
		i = 1;
		while (i < stacks->len_b)
		{
			stacks->stack_b[i - 1] = stacks->stack_b[i];
			i++;
		}
		stacks->stack_b[i - 1] = tmp;
		if (caga == 1)
			write(1, "rb\n", ft_strlen("rb\n"));
	}
}

void	ft_rr(t_stack *stacks, int caga)
{
	ft_ra(stacks, 0);
	ft_rb(stacks, 0);
	if (caga == 1)
		write(1, "rr\n", ft_strlen("rr\n"));
}