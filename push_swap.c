/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/09 16:05:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
	//struct stack*	temp;

	//temp = *head_ref;
	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data; // set o valor;
	new_node->next = NULL; //novo n´p agora ponta para NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	while ((*head_ref)->next != NULL) //percorre a lista até o ultimo nó;
		(*head_ref) = (*head_ref)->next;
	(*head_ref)->next = new_node; //o antigo ultimo agr aponta para o novo nó;
}

void ft_insert_after(struct stack*	node, int	new_data)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_swap_a(struct stack** stack_a)
{
	struct stack*	node_one;
	struct stack*	node_two;

	node_one = (*stack_a);
	node_two = (*stack_a)->next;

	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
}

void ft_create_a(struct stack** stack_a, char *argv[], int len)
{
	while (len >= 1)
		ft_push(stack_a, atoi(argv[len--])); // tirar atoi;
}

int	main(int argc, char *argv[])
{
	struct stack*	stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	ft_create_a(&stack_a, argv, argc - 1);
	printf("%i\n", stack_a->data);
	printf("%i\n", stack_a->next->data);
	printf("%i\n", stack_a->next->next->data);
//	printf("%i\n", stack_a->next->next->next->data);
	ft_swap_a(&stack_a);
	printf("-----------------\n");
	printf("%i\n", stack_a->data);
	printf("%i\n", stack_a->next->data);
	printf("%i\n", stack_a->next->next->data);
	printf("%i\n", stack_a->next->next->next->data);


	return (0);
}
