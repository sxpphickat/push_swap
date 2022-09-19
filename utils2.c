/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:35:45 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/19 18:09:36 by vipereir         ###   ########.fr       */
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

int	ft_max_value(t_stack **list)
{
	t_stack	**aux;
	size_t	max;

	aux = list;
	max = 0;
	while (*aux != NULL)
	{
		if ((*aux)->index > max)
			max = (*aux)->index;
		aux = &(*aux)->next;
	}
	return (max);
}

void	ft_index(t_stack **a, t_stack **f)
{
	int		i;
	t_stack	*temp;
	t_stack	*tempf;

	temp = (*a);
	tempf = (*f);
	i = 0;
	while (tempf)
	{
		while (temp->data != tempf->data)
			temp = temp->next;
		temp->index = i;
		i++;
		temp = (*a);
		tempf = tempf->next;
	}
}

int	ft_len(t_stack **x)
{
	int		i;
	t_stack	*temp;

	temp = (*x);
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
