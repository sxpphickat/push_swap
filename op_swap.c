/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:35:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:26:16 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*node_one;
	t_stack	*node_two;

	if ((*stack_a)->next == NULL)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*node_one;
	t_stack	*node_two;

	if ((*stack_b)->next == NULL)
		return ;
	node_one = (*stack_b);
	node_two = (*stack_b)->next;
	*stack_b = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_one;
	t_stack	*node_two;
	t_stack	*node_one_b;
	t_stack	*node_two_b;

	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
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
