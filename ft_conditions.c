/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:49:21 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:21:10 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_bigger_index(t_stack **stack_a)
{
	t_stack	*temp;
	size_t	big;

	temp = (*stack_a);
	big = temp->index;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if (big < temp->index) 
			big = temp->index;
	}
	return(big);
}

int		ft_find_best_index(t_stack **stack_a, int len, size_t find)
{
	t_stack	*temp;
	int				movs;

	movs = 0;
	temp = (*stack_a);
	while(temp->index != find)
	{
		temp = temp->next;
		movs++;
	}
	if (movs > len / 2)
		return(1);
	else
		return (2);
}

size_t		ft_smaller_index(t_stack **stack_a)
{
	t_stack	*temp;
	size_t	small;

	temp = (*stack_a);
	small = temp->index;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if (small > temp->index)
			small = temp->index;
	}
	return(small);
}

size_t		ft_smallerb_index(t_stack **stack_a, size_t better)
{
	t_stack	*temp;
	size_t	small;

	temp = (*stack_a);
	small = better;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if (small > temp->index && small > better)
			small = temp->index;
	}
	return(small);
}
