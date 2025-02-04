/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_p2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:17:48 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:19:51 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complete_rotation_a(t_list **a, t_list *node)
{
	int	size;

	size = stack_size(*a);
	while (*a != node)
	{
		if (node->indice <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	complete_rotation_b(t_list **b, t_list *node)
{
	int	size;

	size = stack_size(*b);
	while (*b != node)
	{
		if (node->indice <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	move_a_b(t_list *cheapst, t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	if (cheapst->indice <= size_b / 2 && cheapst->target->indice <= size_a / 2)
	{
		while (*b != cheapst && *a != cheapst->target)
			rr(a, b);
	}
	else if (cheapst->indice > size_b / 2 && cheapst->target->indice > size_a
		/ 2)
	{
		while (*b != cheapst && *a != cheapst->target)
			rrr(a, b);
	}
	set_indice(*a);
	set_indice(*b);
	complete_rotation_a(a, cheapst->target);
	complete_rotation_b(b, cheapst);
}

void	push_to_b(t_list **a, t_list **b)
{
	int	pivo;

	while (stack_size(*a) > 3)
	{
		pivo = (stack_size(*a)) / 3;
		if (stack_size(*a) == 5)
		{
			sort_five(a, b);
			break ;
		}
		if ((*a)->rank <= pivo)
		{
			pb(a, b);
			init_arr(*a, NULL);
		}
		else
			ra(a);
	}
}

void	push_to_a(t_list **a, t_list **b)
{
	t_list	*cheapst;

	while (*b)
	{
		set_indice(*a);
		set_indice(*b);
		set_target(*a, *b);
		set_cost(*a, *b);
		cheapst = chose_cheapst(*b);
		move_a_b(cheapst, a, b);
		pa(a, b);
	}
}
