/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:37:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 17:11:27 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_sort_check(t_stack **stack_a, int len)
{
	t_stack	*temp;
	int		i;

	i = 0;
	len = ft_len(stack_a);
	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
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

void	ft_pt2(t_stack **a, t_stack **b)
{
	while ((*b))
		pa(a, b);
}

int	ft_iterate_a(t_stack **a, t_stack **b, int i)
{
	int	len;
	int	j;

	j = 0;
	len = ft_len(a);
	while (j < len)
	{
		if ((*a)->index & (1 << i))
			ra(a);
		else
			pb(a, b);
		if (!ft_sort_check(a, len) && !ft_rev_sort_check(b, len))
			return (1);
		j++;
	}
	return (0);
}

void	ft_iterate_b(t_stack **a, t_stack **b, int i)
{
	int	len;
	int	j;

	j = 0;
	len = ft_len(b);
	while (j < len)
	{
		if ((*b)->index & (1 << i))
			pa(a, b);
		else
			rb(b);
		j++;
	}
}

void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a)
{
	int	i;
	int	j;
	int	big;
	int	len;

	ft_index(a, fake_a);
	j = 0;
	i = 0;
	len = ft_len(a);
	big = ft_bigger(a);
	while (i < 999)
	{
		len = ft_len(a);
		while (j < len)
		{
			if ((*a)->index & (1 << i))
				ra(a);
			else
				pb(a, b);
			j++;
			if (!ft_sort_check(a, len) && !ft_rev_sort_check(b, len))
				return ;
		}
		i++;
		j = 0;
		len = ft_len(b);
		while (j < len)
		{
			if ((*b)->index & (1 << i))
				pa(a, b);
			else
				rb(b);
			j++;
		}
		j = 0;
	}
	while ((*b))
		pa(a, b);
}


/*
void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a)
{
	int	i;

	ft_index(a, fake_a);
	i = 0;
	while (i < 8)
	{
		if (ft_iterate_a(a, b, i) == 1)
			return ;
		i++;
		ft_iterate_b(a, b, i);
	}
}*/


