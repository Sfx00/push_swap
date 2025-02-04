/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:10:12 by obajali           #+#    #+#             */
/*   Updated: 2025/02/01 18:46:10 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//----------header_files---------//
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//------macro---------//
# define BUFFER_SIZE 3

//------------structure------------//
typedef struct s_list
{
	int				number;
	struct s_list	*next;
	int				rank;
	struct s_list	*target;
	int				indice;
	long			cost_total;
}					t_list;

//-----------operations-------------//
void				sa(t_list **stack);
void				sb(t_list **stack);
void				ss(t_list **stack_A, t_list **stack_B);
void				pa(t_list **stack_A, t_list **stack_B);
void				pb(t_list **stack_A, t_list **stack_B);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stack_A, t_list **stack_B);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stack_B, t_list **stack_A);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rot(t_list **stack);
void				push(t_list **stack_1, t_list **stack_2);

//---------set_element_of_struct--------//
void				set_indice(t_list *stack);
void				set_rank(int *n, t_list *stack);
void				set_min_target(t_list *a, t_list *b);
void				set_target(t_list *a, t_list *b);
int					max_cost(int cost_a, int cost_b);
void				set_cost(t_list *a, t_list *b);

//--------stack_operations-----------//
int					stack_size(t_list *stack);
void				addt_stack(int nb, t_list **stack, int *flag);
void				free_stack(t_list **stack);
t_list				*min_node(t_list *stack);
t_list				*max_node(t_list *list);
int					stack_size(t_list *stack);
void				stack_check(char **av, t_list **stack);
void				add_back(t_list *list, t_list *node);
t_list				*last_list(t_list *p);
void				add_null(t_list *node, t_list *stack);

//-----------sort_operations----------//
int					check_sorted(t_list *stack);
void				sort_3(t_list **stack);
void				sort_five(t_list **a, t_list **b);
void				rocket_sort(t_list **a);
void				init_arr(t_list *stack, int *n);
void				quick_sort(int *n, int start, int end);

//----------algorithm----------------//
t_list				*chose_cheapst(t_list *b);
void				complete_rotation_a(t_list **a, t_list *node);
void				complete_rotation_b(t_list **b, t_list *node);
void				move_a_b(t_list *cheapst, t_list **a, t_list **b);
void				push_to_b(t_list **a, t_list **b);
void				push_to_a(t_list **a, t_list **b);

//---------------tools----------------//
char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
t_list				*create_node(int nb);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
long				ft_atol(char *str);
t_list				*last_node(t_list *p, int nb, int *flag);
t_list				*create_node(int nb);
void				error(char **buffer, t_list **stack);
void				*free_strings(char **s);
char				**ft_split(char const *s, char c);
int					check_input(char *buffer, long *nb);

#endif