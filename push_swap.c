/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/09 14:31:43 by vipereir         ###   ########.fr       */
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

void ft_create_a(struct stack** stack_a, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
		ft_push(stack_a, atoi(argv[i++])); // tirar atoi;
}

int	main(int argc, char *argv[])
//int	main(void)
{
	struct stack*	stack_a;

	(void) argc;
	stack_a = NULL;
	ft_create_a(&stack_a, argv);
	printf("%i\n", stack_a->data);
	printf("%i\n", stack_a->next->data);
	printf("%i\n", stack_a->next->next->data);
	printf("%i\n", stack_a->next->next->next->data);

	return (0);
}
