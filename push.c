/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:52:54 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/07 21:46:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top;

	top = *b;
	*b = top->next;
	//ft_fprintf(1, "pa() --> a.n = (%d)\n", top->n);
	ft_lstadd_front(a, top);
	ft_fprintf(1, "pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*top;

	top = *a;
	*a = top->next;
	//ft_fprintf(1, "pb() --> b.n (%d)\n", top->n);
	ft_lstadd_front(b, top);
	ft_fprintf(1, "pb\n");
}
