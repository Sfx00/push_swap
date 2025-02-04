/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:46:23 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:09:33 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char **buffer, t_list **stack)
{
	t_list	*tmp;
	t_list	*p;

	if (buffer)
	{
		free_strings(buffer);
	}
	if (stack)
	{
		tmp = *stack;
		while (tmp)
		{
			p = tmp->next;
			free(tmp);
			tmp = p;
		}
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	start_sort(t_list **a)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else
		rocket_sort(a);
}

void	stack_check(char **av, t_list **stack)
{
	char	**buffer;
	long	nb;
	int		i;
	int		x;
	int		flag;

	i = 0;
	flag = 0;
	while (av[i])
	{
		buffer = ft_split(av[i], ' ');
		if (!*buffer)
			error(buffer, stack);
		x = 0;
		while (buffer[x] && check_input(buffer[x], &nb) == 1 && flag == 0)
		{
			addt_stack(nb, stack, &flag);
			x++;
		}
		if (buffer[x] || flag == 1)
			error(buffer, stack);
		free_strings(buffer);
		i++;
	}
}

int	check_input(char *buffer, long *nb)
{
	int		i;
	size_t	lent;

	i = 0;
	lent = ft_strlen(buffer);
	if (lent > 11)
		return (0);
	if ((buffer[i] == '-' || buffer[i] == '+') && buffer[i + 1])
		i++;
	while (buffer[i] && (buffer[i] >= '0' && buffer[i] <= '9'))
		i++;
	if (buffer[i])
		return (0);
	*nb = ft_atol(buffer);
	if (*nb > INT_MAX || *nb < INT_MIN)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*head;
	int		*n;

	head = NULL;
	n = NULL;
	if (ac == 1)
		exit(1);
	stack_check(av + 1, &head);
	if (check_sorted(head) == 0)
	{
		init_arr(head, n);
		start_sort(&head);
	}
	free_stack(&head);
}
