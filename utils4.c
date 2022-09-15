/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:36:41 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 16:38:09 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
