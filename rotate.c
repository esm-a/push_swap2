/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:04:28 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/07 21:46:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;

	first = *a;
	//ft_fprintf(1, "ra() --> a.n = %d\n", (*a)->n);
	ft_lstlast(*a)->next = first;
	*a = first->next;
	first->next = NULL;
	ft_fprintf(1, "ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;

	first = *b;
	//ft_fprintf(1, "rb() --> b.n = %d\n", (*b)->n);
	ft_lstlast(*b)->next = first;
	*b = first->next;
	first->next = NULL;
	ft_fprintf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_fprintf(1, "rr\n");
}
