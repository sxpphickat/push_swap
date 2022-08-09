/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/09 17:24:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft/libft.h"

//stack

struct	stack {
	int		data;
	struct	stack* next;
};

void ft_push(struct stack** head_ref, int	data)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack)); //aloca espaço para o node;
	new_node->data = data; // coloca os dados dentro do node;
	new_node->next = (*head_ref); //novo node aponta para a cabeça;
	(*head_ref) = new_node; //a cabeça agr aponta para o node;
}

void ft_append(struct stack** head_ref, int	new_data)
{
	struct stack*	new_node;
	struct stack*	temp;

	temp = *head_ref;
	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data; // set o valor;
	new_node->next = NULL; //novo n´p agora ponta para NULL;
	if (temp == NULL)
	{
		temp = new_node;
		return ;
	}
	while (temp->next != NULL) //percorre a lista até o ultimo nó;
		temp = temp->next;
	temp->next = new_node; //o antigo ultimo agr aponta para o novo nó;
}

void ft_insert_after(struct stack*	node, int	new_data)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_swap_a(struct stack** stack_a, int	len)
{
	struct stack*	node_one;
	struct stack*	node_two;

	if (len < 2)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sa\n", 3);
}

void	ft_swap_b(struct stack** stack_b, int	len)
{
	struct stack*	node_one;
	struct stack*	node_two;

	if (len < 2)
		return ;
	node_one = (*stack_b);
	node_two = (*stack_b)->next;
	*stack_b = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sb\n", 3);
}

void ft_ss(struct stack** stack_a, struct stack** stack_b, int len_a, int len_b)
{
	struct stack*	node_one;
	struct stack*	node_two;
	struct stack*	node_one_b;
	struct stack*	node_two_b;

	if (len_a < 2 || len_b < 2)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	node_one_b = (*stack_b);
	node_two_b = (*stack_b)->next;
	*stack_b = node_two_b;
	node_one_b->next = node_two_b->next;
	node_two_b->next = node_one_b;
	write(1, "ss\n", 3);
}

void ft_create_a(struct stack** stack_a, char *argv[], int len)
{
	while (len >= 1)
		ft_push(stack_a, atoi(argv[len--])); // tirar atoi;
}

void	ft_print_list(struct stack** list_head, char ab)
{
	struct stack*	print_stack;

	if (ab == 'a')
		ft_printf("stack a: ");
	else if (ab == 'b')
		ft_printf("stack b: ");
	print_stack = (*list_head);
	while (print_stack != NULL)
	{
		ft_printf("%i -> ", print_stack->data);
		print_stack = print_stack->next;
	}
	if (print_stack == NULL)
		ft_printf("NULL\n");
}

int	main(int argc, char *argv[])
{
	struct stack*	stack_a;
	struct stack*	stack_b;
	int				len;

	len = argc - 1;
	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_create_a(&stack_a, argv, len);
	ft_create_a(&stack_b, argv, len);
	ft_print_list(&stack_a, 'a');
	ft_print_list(&stack_b, 'b');
	ft_swap_a(&stack_a, len);
	ft_swap_b(&stack_b, len);
	ft_printf("-----------------\n");
	ft_print_list(&stack_a, 'a');
	ft_print_list(&stack_b, 'b');
	ft_ss(&stack_a, &stack_b, len, len);
	ft_printf("-----------------\n");
	ft_print_list(&stack_a, 'a');
	ft_print_list(&stack_b, 'b');

	return (0);
}



