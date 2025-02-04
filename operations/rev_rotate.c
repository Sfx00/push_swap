/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:17:26 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:20:53 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack)
{
	reverse_rot(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	reverse_rot(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_B, t_list **stack_A)
{
	reverse_rot(stack_B);
	reverse_rot(stack_A);
	write(1, "rrr\n", 4);
}

void	reverse_rot(t_list **stack)
{
	t_list	*last;

	last = last_list(*stack);
	add_null(last, *stack);
	last->next = *stack;
	*stack = last;
}
