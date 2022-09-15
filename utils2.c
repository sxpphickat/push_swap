/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:45 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 17:14:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_stack **stack_a, int len)
{
	t_stack	*temp;
	int		i;

	i = 0;
	len = ft_len(stack_a);
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
