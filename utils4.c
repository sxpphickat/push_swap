/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:36:41 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:48:55 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			break ;
	}
	return (temp->data);
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

void	ft_concat(t_stack **stack_a, t_stack **stack_b)
{
	size_t	small;
	size_t	a_max;

	a_max = ft_max_value(stack_a);
	if ((*stack_a)->index > (*stack_b)->index)
		small = (*stack_b)->index;
	else
		small = (*stack_a)->index;
	while ((*stack_b) != NULL)
	{
		if ((*stack_a)->index < (*stack_b)->index)
		{
			if ((*stack_b)->index > a_max)
			{
				a_max = (*stack_a)->index;
				while ((*stack_a)->index != small)
					ra(stack_a);
				pa(stack_a, stack_b);
				ra(stack_a);
			}
			else
				ra(stack_a);
		}
		else
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
	}
	while ((*stack_a)->index != small)
		ra(stack_a);
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
