/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:45 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/13 11:51:32 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_stack **stack_a, int len)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
		{
			temp = temp->next;
			i++;
		}
		else
			return (1);
	}
	if (i == len - 1)
		return (0);
	return (1);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		i;

	i = 0;
	(void)(*stack_b);
	while (ft_sort_check(stack_a, len))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
		ra(stack_a);
		i++;
		if (i == len - 1)
		{
			ra(stack_a);
			i = 0;
		}
	}
}

void	ft_fake_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;

	i = 0;
	(void)(*stack_b);
	while (ft_sort_check(stack_a, len))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			fsa(stack_a);
		fra(stack_a);
		i++;
		if (i == len - 1)
		{
			fra(stack_a);
			i = 0;
		}
	}
}

int	ft_repeat_check(t_stack **stack_a)
{
	t_stack	*temp_stack;
	t_stack	*next;

	temp_stack = (*stack_a);
	next = temp_stack->next;
	while (temp_stack->next)
	{
		while (next)
		{
			if (next->data == temp_stack->data)
				return (1);
			next = next->next;
		}
		temp_stack = temp_stack->next;
		next = temp_stack->next;
	}
	return (0);
}

int	ft_smaller(t_stack **stack_a)
{
	t_stack	*temp;
	int		small;

	temp = (*stack_a);
	small = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (small > temp->data)
			small = temp->data;
	}
	return (small);
}
