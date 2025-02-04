/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ranking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:45:37 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 19:01:41 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *n, int start, int end)
{
	int	pivo;
	int	j;
	int	i;

	pivo = n[end];
	j = start;
	i = (start - 1);
	while (j < end)
	{
		if (n[j] <= pivo)
		{
			i++;
			ft_swap(&n[i], &n[j]);
		}
		j++;
	}
	ft_swap(&n[i + 1], &n[end]);
	return (i + 1);
}

void	quick_sort(int *n, int start, int end)
{
	int	i;

	if (start < end)
	{
		i = partition(n, start, end);
		quick_sort(n, start, i - 1);
		quick_sort(n, i + 1, end);
	}
}

void	set_rank(int *n, t_list *stack)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (stack->number != n[i])
			i++;
		stack->rank = i + 1;
		stack = stack->next;
	}
}

void	init_arr(t_list *stack, int *n)
{
	int		size;
	int		i;
	t_list	*p;

	p = stack;
	size = stack_size(stack);
	n = (int *)malloc((size + 1) * sizeof(int));
	i = 0;
	while (stack)
	{
		n[i] = stack->number;
		stack = stack->next;
		i++;
	}
	quick_sort(n, 0, size - 1);
	set_rank(n, p);
	free(n);
}
