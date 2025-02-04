/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:11:54 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:16:47 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*create_node(int nb)
{
	t_list	*p;

	p = (t_list *)ft_calloc(2, sizeof(t_list));
	if (!p)
		return (NULL);
	p->number = nb;
	p->next = NULL;
	return (p);
}
