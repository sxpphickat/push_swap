/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:42 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:13:12 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_stack **a)
{
	if ((*a)->data == ft_bigger(a))
		ra(a);
	else if ((*a)->next->data == ft_bigger(a))
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	ft_five(t_stack **a, t_stack **b, int len)
{
	while ((*a)->data != ft_smaller(a))
	{
		if (ft_find_best(a, len, ft_smaller(a)) == 1)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	if (len == 5)
	{
		while ((*a)->data != ft_smaller(a))
		{
			if (ft_find_best(a, len, ft_smaller(a)) == 1)
				rra(a);
			else
				ra(a);
		}
		pb(a, b);
	}
	ft_three(a);
	pa(a, b);
	pa(a, b);
}

void	ft_small(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
	{
		if ((*a)->data > ((*a)->next->data))
			sa(a);
	}
	else if (len == 3)
		ft_three(a);
	else if (len <= 5)
		ft_five(a, b, len);
	return ;
}
