/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:20:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:20:43 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **head_ref, int data, size_t index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->index = index;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void	ft_append(t_stack **head_ref, int new_data, size_t index)
{
	t_stack	*new_node;
	t_stack	*temp;

	temp = *head_ref;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->index = index;
	new_node->next = NULL;
	if (temp == NULL)
	{
		temp = new_node;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	ft_insert_after(t_stack *node, int new_data, size_t index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->index = index;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_pop(t_stack **stack_x)
{
	t_stack	*temp;

	if ((*stack_x) == NULL)
		return ;
	temp = (*stack_x);
	(*stack_x) = temp->next;
	temp = NULL;
	free(temp);
}
