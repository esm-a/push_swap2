#include "push_swap.h"

void    ft_free(t_stack *stk)
{
    t_stack *temp;

    while (stk)
    {
        temp = stk;
        stk = stk->next;
        free(temp);
    }
}

void    ft_error(void)
{
    ft_fprintf(2, "Error\n");
    exit(1);
}

void    check_args(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 0;
        if (av[i][j] == '-')
            ++j;
        while (av[i][j])
        {
            if (ft_isdigit(av[i][j]) == 0)
                ft_error();
            ++j;
        }
        ++i;
    }
}

void    ft_duplicate(t_stack **a)
{
    t_stack *stk;
    t_stack *nxt;

    stk = *a;
    while (stk)
    {
        nxt = stk->next;
        while (nxt)
        {
            if (nxt->n == stk->n)
            {
                ft_free(*a);
                ft_error();
            }
            nxt = nxt->next;
        }
        stk = stk->next;
    }
}