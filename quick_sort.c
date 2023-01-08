#include <push_swap.h>

int middle(t_stack *s, int size, int par)
{
	int *arr;
	int	pivot;
	int i;

	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		ft_free(s);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		arr[i++] = s->n;
		s = s->next;
	}
	heap_sort(arr, size);
	pivot = arr[size / par];
	free(arr);
	return (pivot);
}

int	get_largest(t_stack *s, int size)
{
	int	*arr;
	int	largest;
	int	i;

	arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		ft_free(s);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		arr[i++] = s->n;
		s = s->next;
	}
	heap_sort(arr, size);
	largest = arr[size - 1];
	free(arr);
	return (largest);
}

void	push_all_b(t_stack **b, t_stack **a)
{
	while (*b)
		pa(a, b);
}

void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_stack	*s;
	int		size;
	int		largest;

	if (*b == NULL)
		return ;
	if (b_is_sorted(*b) == 1)
	{
		push_all_b(b, a);
		return ;
	}
	else if (ft_lstsize(*b) <= 3)
	{
		sort_three_b(b);
		push_all_b(b, a);
		return ;
	}
	s = *b;
	size = ft_lstsize(s);
	largest = get_largest(s, size);
	best_move_b(b, largest, size);
	pa(a, b);
	push_back_sorted(a, b);
}

int	get_smallest(t_stack *stk)
{
	int	smallest;

	smallest = stk->n;
	stk = stk->next;
	while (stk)
	{
		if (stk->n < smallest)
			smallest = stk->n;
		stk = stk->next;
	}
	return (smallest);
}

int	handle_sizes(t_stack **a, t_stack **b, int *size, int *par)
{
	if (a_is_sorted(*a) == 1)
		return (1);
	*size = ft_lstsize(*a);
	if (*size <= 3)
	{
		sort_three_a(a);
		return (1);
	}
	if (*size <= 5)
	{
		sort_five(a, b);
		return (1);
	}
	*par = 2;
	if (*size >= 50 && *size <= 100)
		*par = 4;
	if (*size > 100)
		*par = 6;
	return (0);
}

void	quick_sort_a(t_stack **a, t_stack **b)
{
	t_stack	*s;
	int		size;
	int		mid;
	int		par;
	int		n;

	if (handle_sizes(a, b, &size, &par) == 1)
		return ;
	s = *a;
	mid = middle(s, size, par);
	while (s)
	{
		if (s->n < mid)
		{
			n = s->n;
			s = s->next;
			best_move_a(a, n, size);
			pb(b, a);
			--size;
		}
		else
			s = s->next;
	}
	quick_sort_a(a, b);
}