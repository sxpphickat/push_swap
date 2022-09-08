/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:29:51 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:41:17 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_x(t_stack **stack_a, char *argv[], int len)
{
	while (len >= 1)
		ft_push(stack_a, ft_atoi(argv[len--]), 0);
}

void	ft_print_list(t_stack **list_head, char ab)
{
	t_stack	*print_stack;

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

void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	write(1, "\n", 1);
	while (temp_a != NULL || temp_b != NULL)
	{
		if (temp_a != NULL)
		{
			ft_printf("%i -> %i", temp_a->data, temp_a->index);
			temp_a = temp_a->next;
		}
		write(1, "   ", 3);
		if (temp_b != NULL)
		{
			ft_printf("%i -> %i", temp_b->data, temp_b ->index);
			temp_b = temp_b->next;
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	write(1, "-  -\n", 5);
	write(1, "a  b\n", 5);
}

void	fsa(t_stack **stack_a)
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
}

void	fra(t_stack **stack_a)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
}
