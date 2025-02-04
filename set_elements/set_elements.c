/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:45:33 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:23:20 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indice(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->indice = i;
		i++;
		stack = stack->next;
	}
}

void	set_min_target(t_list *a, t_list *b)
{
	init_arr(a, NULL);
	while (a)
	{
		if (a->rank == 0)
			b->target = a;
		a = a->next;
	}
}

void	set_target(t_list *a, t_list *b)
{
	t_list	*p;
	int		flag;
	long	target_number;

	while (b)
	{
		b->target = a;
		target_number = LONG_MAX;
		p = a;
		flag = 0;
		while (p)
		{
			if (p->number > b->number && p->number < target_number)
			{
				flag = 1;
				b->target = p;
				target_number = p->number;
			}
			p = p->next;
		}
		if (flag == 0)
			set_min_target(a, b);
		b = b->next;
	}
}

int	max_cost(int cost_a, int cost_b)
{
	int	max;

	max = 0;
	if (cost_a > cost_b)
		max = cost_a;
	else if (cost_b > cost_a)
		max = cost_b;
	else
		max = cost_b;
	return (max);
}

void	set_cost(t_list *a, t_list *b)
{
	int	cost_a;
	int	cost_b;
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->indice <= size_b / 2)
			cost_b = b->indice;
		else
			cost_b = size_b - b->indice;
		if (b->target->indice <= size_a / 2)
			cost_a = b->target->indice;
		else
			cost_a = size_a - b->target->indice;
		if ((b->indice <= size_b / 2 && b->target->indice <= size_a / 2)
			|| (b->target->indice > size_a / 2 && b->target->indice > size_a
				/ 2))
			b->cost_total = max_cost(cost_a, cost_b);
		else
			b->cost_total = cost_a + cost_b;
		b = b->next;
	}
}
