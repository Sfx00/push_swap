/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:38:28 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 20:54:33 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	app_operation(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(buffer, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		(swap(stack_a), swap(stack_b));
	else if (ft_strncmp(buffer, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		(rotate(stack_a), rotate(stack_b));
	else if (ft_strncmp(buffer, "rra\n", 4) == 0)
		reverse_rot(stack_a);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		reverse_rot(stack_b);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		(reverse_rot(stack_a), reverse_rot(stack_b));
	else
		(free(buffer), write(2, "error\n", 6), exit(1));
}

void	stack_check(char **av, t_list **stack)
{
	char	**buffer;
	long	nb;
	int		x;
	int		i;
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

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*buffer;

    buffer = get_next_line(0);
	while (buffer)
	{
		app_operation(buffer, stack_a, stack_b);
		free(buffer);
		buffer = get_next_line(0);
	}
	free(buffer);
	if (check_sorted(*stack_a) == 1 && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(1);
	stack_check(av + 1, &stack_a);
	checker(&stack_a, &stack_b);
}
