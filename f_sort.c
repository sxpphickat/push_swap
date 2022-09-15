/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:36:04 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 16:42:33 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bigger(t_stack **stack_a)
{
	t_stack	*temp;
	int		big;

	temp = (*stack_a);
	big = temp->data;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (big < temp->data)
			big = temp->data;
	}
	return (big);
}

long	ft_smaller(t_stack **stack_a)
{
	t_stack	*temp;
	long	small;

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

int	ft_find_best(t_stack **stack_a, int len, long find)
{
	t_stack	*temp;
	int		movs;

	movs = 0;
	temp = (*stack_a);
	while (temp->data != find)
	{
		temp = temp->next;
		movs++;
	}
	if (movs > len / 2)
		return (1);
	else
		return (2);
}

void	ft_super_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	r;
	int	small;

	(void)stack_b;
	small = ft_smaller(stack_a);
	r = ft_find_best(stack_a, len, small);
	while ((*stack_a) != NULL)
	{
		while ((*stack_a)->data != small)
		{
			if (r == 1)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		if ((*stack_a) != NULL)
		{
			small = ft_smaller(stack_a);
			r = ft_find_best(stack_a, len, small);
		}
	}
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b);
}
