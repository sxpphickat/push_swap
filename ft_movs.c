/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:20:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/30 09:38:39 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(struct stack** head_ref, int	data, unsigned int index)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack)); //aloca espaço para o node;
	new_node->data = data; // coloca os dados dentro do node;
	new_node->index = index; // coloca os dados dentro do node;
	new_node->next = (*head_ref); //novo node aponta para a cabeça;
	(*head_ref) = new_node; //a cabeça agr aponta para o node;
}

void ft_append(struct stack** head_ref, int	new_data, unsigned int index)
{
	struct stack*	new_node;
	struct stack*	temp;

	temp = *head_ref;
	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data; // set o valor;
	new_node->index = index; // set o valor;
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

void ft_insert_after(struct stack*	node, int	new_data, unsigned int	index)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data;
	new_node->index = index;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_pop(struct stack** stack_x)
{
	struct stack* temp;

	if ((*stack_x) == NULL)
		return ;
	temp = (*stack_x);
	(*stack_x) = temp->next;
	temp = NULL;      //deleta o conteudo;
	free(temp);
}
