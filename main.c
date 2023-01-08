/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:41:46 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/06 21:48:48by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*s;
	int		val;

	if (argc == 1)
		exit(1);
	check_args(argv);
	a = b = NULL;
	while (*++argv)
	{
		val = ft_atoi(*argv);
		if (val == -1 && ft_strlen(*argv) > 2)
		{
			ft_free(a);
			ft_error();
		}
		s = ft_lstnew(val);
		if (s == NULL)
		{
			ft_free(a);
			ft_error();
		}
		ft_lstadd_back(&a, s);
	}
	ft_duplicate(&a);
	//sort(&a, &b);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "\t(%d) --> [%d]\n", s->n, s->indx);
	//	s = s->next;
	//}
	//ft_fprintf(1, "\n\tstack a\n");
	//merge_sort(&a);
	//sort_five(&a, &b);
	if (is_sorted(a))
		exit(0);
	quick_sort_a(&a, &b);
	push_back_sorted(&a, &b);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "\t(%d) --> [%d]\n", s->n, s->indx);
	//	s = s->next;
	//}
	//ft_fprintf(1, "\n\tstack a\n");
	//pb(&b, &a);
	//pb(&b, &a);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "\t(%d)\n", s->n);
	//	s = s->next;
	//}
	//ft_fprintf(1, "\n\tstack a\n");
	//ft_fprintf(1, "\n%d\t%d\n", b->n, b->next->n);
	//s = a;
	//while (s)
	//{
	//	ft_fprintf(1, "|%d|\t", s->n);
	//	s = s->next;
	//}
	//system("leaks push_swap");
}

//void	error(void)
//{
//	ft_fprintf(2, "Error\n");
//	exit(1);
//}

//static void	check_args(char **av)
//{
//	int	i;
//	int	j;

//	i = 1;
//	while (av[i])
//	{
//		j = 0;
//		if (av[i][j] == '-')
//			j++;
//		while (av[i][j])
//		{
//			if (ft_isdigit(av[i][j]) == 0)
//				error();
//			j++;
//		}
//		i++;
//	}
//}

//static void	duplicate(t_stack *stk)
//{
//	t_stack	*nxt;

//	while (stk)
//	{
//		nxt = stk->next;
//		while (nxt)
//		{
//			if (nxt->n == stk->n)
//				error();
//			nxt = nxt->next;
//		}
//		stk = stk->next;
//	}
//}
