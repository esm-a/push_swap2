#include "push_swap.h"

void    rr_machine(t_stack **s, int count, void (*rr)(t_stack **))
{
	while (count-- > 0)
		(*rr)(s);
}

void    rrr_machine(t_stack **s, int count, void (*rrr)(t_stack **))
{
	while (count-- > 0)
		(*rrr)(s);
}

void	put_on_top(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 3)
	{
		rra(a);
		pa(a, b);
		rr_machine(a, 2, ra);
	}
	else
	{
		rr_machine(a, 2, ra);
		pa(a, b);
		rrr_machine(a, 2, rra);
	}
}

void	handle(t_stack **b, t_stack **a)
{
	if ((*b)->n < (*a)->n)
		pa(a, b);
	else if ((*b)->n > ft_lstlast(*a)->n)
	{
		pa(a, b);
		sa(*a);
	}
	else if ((*b)->n > (*a)->next->n && (*b)->n < (*a)->next->next->n)
		put_on_top(a, b);
	else if ((*b)->n > (*a)->next->next->n)
	{
		rra(a);
		pa(a, b);
		rr_machine(a, 2, ra);
	}
}

void    sort_five(t_stack **a, t_stack **b)
{
	int i;

	pb(b, a);
	pb(b, a);
	sort_three_a(a);
	i = 2;
	while (*b && i-- > 0)
		handle(b, a);
}