/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:29:37 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:33:30 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*last_node(t_list *p, int nb, int *flag)
{
	while (p->next)
	{
		if (p->number == nb)
			*flag = 1;
		p = p->next;
	}
	if (p->number == nb)
		*flag = 1;
	return (p);
}

t_list	*last_list(t_list *p)
{
	while (p->next)
		p = p->next;
	return (p);
}

void	add_back(t_list *list, t_list *node)
{
	t_list	*last;

	last = last_list(list);
	last->next = node;
}

void	add_null(t_list *node, t_list *stack)
{
	while (stack->next != node)
		stack = stack->next;
	stack->next = NULL;
}

void	addt_stack(int nb, t_list **stack, int *flag)
{
	t_list	*p;

	if (*stack)
	{
		p = last_node(*stack, nb, flag);
		p->next = create_node(nb);
	}
	else
		*stack = create_node(nb);
}
