/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:35:58 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 17:09:58 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4

//-----------structure--------------//
typedef struct s_list
{
	int				number;
	struct s_list	*next;
	int				level;
	struct s_list	*target;
	int				indice;
	long			cost_total;
}					t_list;

//---------------opertions------------------------//

void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rot(t_list **stack);
void				push(t_list **stack_1, t_list **stack_2);

//------------------tools--------------------//
int					stack_size(t_list *stack);
void				addt_stack(int nb, t_list **stack, int *flag);
void				free_stack(t_list **stack);
void				stack_check(char **av, t_list **stack);
int					check_sorted(t_list *stack);
char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
t_list				*create_node(int nb);
void				*ft_memset(void *s, int c, size_t n);
long				ft_atol(char *str);
t_list				*last_node(t_list *p, int nb, int *flag);
void				error(char **buffer, t_list **stack);
void				*free_strings(char **s);
char				**ft_split(char const *s, char c);
int					check_input(char *buffer, long *nb);
void				add_back(t_list *list, t_list *node);
t_list				*last_list(t_list *p);
void				add_null(t_list *node, t_list *stack);

#endif