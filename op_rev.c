/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:39:32 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/30 09:41:24 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(struct s_stack **stack_a)
{
	struct s_stack	*temp;
	struct s_stack	*temp_free;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_a, temp->next->data, temp->next->index);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(struct s_stack **stack_b)
{
	struct s_stack	*temp;
	struct s_stack	*temp_free;

	if ((*stack_b)->next == NULL)
		return ;
	temp = (*stack_b);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_b, temp->next->data, temp->next->index);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*temp;
	struct s_stack	*temp_free;
	struct s_stack	*temp_b;
	struct s_stack	*temp_free_b;

	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_a, temp->next->data, temp->next->index);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	temp_b = (*stack_b);
	while (temp_b->next->next != NULL)
		temp_b = temp_b->next;
	ft_push(stack_b, temp_b->next->data, temp_b->next->index);
	temp_free_b = temp_b->next;
	free(temp_free_b);
	temp_b->next = NULL;
	write(1, "rrr\n", 4);
}
