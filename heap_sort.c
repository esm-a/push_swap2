#include "push_swap.h"

#define	LEFT(i)		(2 * i + 1)
#define	RIGHT(i)	(2 * i + 2)

void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void    max_heapify(int *arr, int i, int size)
{
	int largest;
	int l;
	int r;

	l = LEFT(i);
	r = RIGHT(i);
	if (l < size && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	if (r < size && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr, largest, i);
		max_heapify(arr, largest, size);
	}
}

void	build_max_heap(int *arr, int size)
{
	int	i;

	i = size / 2 - 1;
	while (i >= 0)
		max_heapify(arr, i--, size);
}

void	heap_sort(int *arr, int size)
{
	int	i;

	build_max_heap(arr, size);
	i = size - 1;
	while (i >= 1)
	{
		swap(arr, i, 0);
		max_heapify(arr, 0, --size);
		--i;
	}
}