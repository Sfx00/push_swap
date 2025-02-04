/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:39:50 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:34:36 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*t;

	if (!*stack_1)
		return ;
	t = *stack_1;
	*stack_1 = (*stack_1)->next;
	t->next = *stack_2;
	*stack_2 = t;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	add_back(*stack, tmp);
}

void	swap(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*stack = tmp2;
}

void	reverse_rot(t_list **stack)
{
	t_list	*last;

	last = last_list(*stack);
	add_null(last, *stack);
	last->next = *stack;
	*stack = last;
}

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
