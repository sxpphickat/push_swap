/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:49:21 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/05 14:36:24 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int		ft_bigger_index(struct s_stack **stack_a)
{
	struct s_stack	*temp;
	unsigned int	big;

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

int		ft_find_best_index(struct s_stack **stack_a, int len, unsigned int find)
{
	struct s_stack	*temp;
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

unsigned int		ft_smaller_index(struct s_stack **stack_a)
{
	struct s_stack	*temp;
	unsigned int	small;

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

unsigned int		ft_smallerb_index(struct s_stack **stack_a, unsigned int better)
{
	struct s_stack	*temp;
	unsigned int	small;

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
