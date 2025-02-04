/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_p1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:46:29 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:18:15 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *stack)
{
	int	nb;

	nb = stack->number;
	while (stack->next)
	{
		stack = stack->next;
		if (nb > stack->number)
		{
			return (0);
		}
		nb = stack->number;
	}
	return (1);
}

void	sort_3(t_list **stack)
{
	t_list	*max_nb;

	max_nb = max_node(*stack);
	if (max_nb == *stack)
		ra(stack);
	else if (max_nb == (*stack)->next)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

void	sort_five(t_list **a, t_list **b)
{
	while (*a != min_node(*a))
	{
		if (min_node(*a)->indice < stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	set_indice(*a);
	while (*a != min_node(*a))
	{
		if (min_node(*a)->indice < stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	rocket_sort(t_list **a)
{
	t_list	*b;
	t_list	*min;

	b = NULL;
	push_to_b(a, &b);
	if (stack_size(*a) == 3)
		sort_3(a);
	push_to_a(a, &b);
	if (!check_sorted(*a))
	{
		min = min_node(*a);
		while (*a != min)
		{
			if (min->indice <= stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
		}
	}
}

t_list	*chose_cheapst(t_list *b)
{
	t_list	*cheapst;
	long	c;

	c = LONG_MAX;
	while (b)
	{
		if (c > b->cost_total)
		{
			c = b->cost_total;
			cheapst = b;
		}
		b = b->next;
	}
	return (cheapst);
}
