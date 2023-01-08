/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:07:30 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/08 22:38:18by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_fprintf.h"

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void    quick_sort_a(t_stack **a, t_stack **b);
void    push_back_sorted(t_stack **a, t_stack **b);
void    heap_sort(int *arr, int size);

void    best_move_a(t_stack **a, int n, int size);
void    best_move_b(t_stack **b, int n, int size);

void     sort_three_a(t_stack **a);
void     sort_three_b(t_stack **b);
int     a_is_sorted(t_stack *a);
int     b_is_sorted(t_stack *b);

void    small_sort_a(t_stack **a);
void    small_sort_b(t_stack **b, t_stack **a);

void    sort_five(t_stack **a, t_stack **b);
void    rr_machine(t_stack **a, int count, void (*rr)(t_stack **));
void    rrr_machine(t_stack **a, int count, void (*rrr)(t_stack **));

void    ft_error(void);
void    ft_free(t_stack *stk);
void    check_args(char **av);
void    ft_duplicate(t_stack **a);

#endif