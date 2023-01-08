#include "push_swap.h"

void    small_sort_a(t_stack **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return ;
    if (ft_lstsize(*a) == 3)
        sort_three_a(a);
    else if ((*a)->n > (*a)->next->n)
        sa(*a);
}

void	small_sort_b(t_stack **b, t_stack **a)
{
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		pa(a, b);
	else if ((*b)->indx == 1)
		pa(a, b);
	else if ((*b)->n > (*b)->next->n)
	{
		pa(a, b);
		pa(a, b);
	}
	else
	{
		sb(*b);
		pa(a, b);
		pa(a, b);
	}
}