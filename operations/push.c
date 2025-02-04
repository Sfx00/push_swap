/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:15:01 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:20:56 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_A, t_list **stack_B)
{
	t_list	*b;

	if (!*stack_B)
		return ;
	b = *stack_B;
	*stack_B = (*stack_B)->next;
	b->next = *stack_A;
	*stack_A = b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_A, t_list **stack_B)
{
	t_list	*b;

	if (!*stack_A)
		return ;
	b = *stack_A;
	*stack_A = (*stack_A)->next;
	b->next = *stack_B;
	*stack_B = b;
	write(1, "pb\n", 3);
}

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
