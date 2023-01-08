#include "push_swap.h"

int a_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int b_is_sorted(t_stack *b)
{
	while (b && b->next)
	{
		if (b->n < b->next->n)
			return (0);
		b = b->next;
	}
	return (1);
}

void    sort_three_a(t_stack **a)
{
	if (a_is_sorted(*a) == 1)
		return ;
	if (ft_lstsize(*a) == 2)
	{
		sa(*a);
		return ;
	}
	if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
		ra(a);
	if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
		sa(*a);
	if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
	{
		rra(a);
		sort_three_a(a);
	}
}

void    sort_three_b(t_stack **b)
{
	if (b_is_sorted(*b) == 1)
		return ;
	if (ft_lstsize(*b) == 2)
	{
		sb(*b);
		return ;
	}
	if ((*b)->n < (*b)->next->n && (*b)->n < (*b)->next->next->n)
		rb(b);
	if ((*b)->n < (*b)->next->n && (*b)->n > (*b)->next->next->n)
		sb(*b);
	if ((*b)->n > (*b)->next->n && (*b)->next->n < (*b)->next->next->n)
	{
		rrb(b);
		sort_three_b(b);
	}
}