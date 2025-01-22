#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H



#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_list
{
    int number;
    struct s_list *next;
    int level;
}t_list;

void sa(t_list **stack);
void ra(t_list **stack_A);
void rra(t_list **stack_A);


void	*ft_calloc(size_t nmemb, size_t size);
t_list *create_node(int nb);


#endif