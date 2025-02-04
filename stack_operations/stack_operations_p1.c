/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_p1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:14:23 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:16:23 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
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

t_list	*min_node(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (min->number > stack->number)
		{
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*p;

	tmp = *stack;
	while (tmp)
	{
		p = tmp->next;
		free(tmp);
		tmp = p;
	}
	*stack = NULL;
}

t_list	*max_node(t_list *list)
{
	int		nb;
	t_list	*save;

	nb = list->number;
	save = list;
	while (list->next)
	{
		list = list->next;
		if (nb < list->number)
		{
			nb = list->number;
			save = list;
		}
	}
	return (save);
}
