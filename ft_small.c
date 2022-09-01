/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:42 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/01 13:56:17 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(struct s_stack **a)
{
	if ((*a)->data == ft_bigger(a))
		ra(a);
	else if ((*a)->next->data == ft_bigger(a))
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	ft_five(struct s_stack **a, struct s_stack **b, int len)
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
