/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:17:46 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:34:19 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (!p)
	{
		return (NULL);
	}
	ft_memset(p, 0, nmemb * size);
	return (p);
}

long	ft_atol(char *str)
{
	long	r;
	int		d;
	int		i;

	i = 0;
	d = 0;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			d = 1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (d == 1)
		return (-r);
	return (r);
}
