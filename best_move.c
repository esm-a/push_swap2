#include "push_swap.h"

static int	lucky_a(t_stack **a, int n);
static int	lucky_b(t_stack **b, int n);

void    best_move_a(t_stack **a, int n, int size)
{
	t_stack *s;
	int     counter;

	if (lucky_a(a, n) == 1)
		return ;
	s = *a;
	counter = 0;
	while (s)
	{
		if (s->n == n)
			break ;
		s = s->next;
		++counter;
	}
	if (counter <= size / 2)
		rr_machine(a, counter, ra);
	else
	{
		counter = size - counter;
		rrr_machine(a, counter, rra);
	}
}

void	best_move_b(t_stack **b, int n, int size)
{
	t_stack	*s;
	int		counter;

	if (lucky_b(b, n) == 1)
		return ;
	s = *b;
	counter = 0;
	while (s)
	{
		if (s->n == n)
			break ;
		++counter;
		s = s->next;
	}
	if (counter <= size / 2)
		while (counter-- > 0)
			rb(b);
	else
	{
		counter = size - counter;
		while (counter-- > 0)
			rrb(b);
	}
}

static int lucky_a(t_stack **a, int n)
{
	if ((*a)->n == n)
		return (1);
	if (ft_lstlast(*a)->n == n)
	{
		rra(a);
		return (1);
	}
	return (0);
}

static int lucky_b(t_stack **b, int n)
{
	if ((*b)->n == n)
		return (1);
	if ((*b)->next->n == n)
	{
		sb(*b);
		return (1);
	}
	if (ft_lstlast(*b)->n == n)
	{
		rrb(b);
		return (1);
	}
	return (0);
}