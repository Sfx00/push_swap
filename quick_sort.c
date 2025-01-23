#include "push_swap.h"



void    swap(int *t, int *p)
{
    int tmp;

    tmp = *t;
    *t = *p;
    *p = tmp;
}
int partition(int *n, int start, int end)
{
    int pivo;
    int i, j;

    pivo  = n[end];
    i = start;
    j = (start - 1);
    while(i < end)
    {
        if(n[i] <= pivo)
        {
            j++;
            swap(&n[j],&n[i]);
        }
        i++;
    }
    swap(&n[j + 1], &n[i]);
    return(j + 1);
}
void    quick_sort(int *n, int start, int end)
{
    int i;

    i = 0;

    while(start < end)
    {
        i = partition(n,start, end);
        quick_sort(n,start,i - 1);
        quick_sort(n, i + 1, end);
    }
}




void    set_level(int *n, t_list *stack)
{
    int i;

    
    while(stack)
    {
        i = 0;
        while(stack->number != n[i])
            i++;
        stack->level = i;
        stack = stack->next;
    }
}