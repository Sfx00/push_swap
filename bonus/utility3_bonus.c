/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:57:56 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:34:58 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
