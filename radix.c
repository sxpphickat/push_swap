/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:37:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/14 11:05:18 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pt2(t_stack **a, t_stack **b)
{
	while ((*b))
		pa(a, b);
}

void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a, int len)
{
	int	i;
	int	j;

	ft_index(a, fake_a);
	j = 0;
	i = 0;
	while (i < 9)
	{
		len = ft_len(a);
		while (j < len)
		{
			if ((*a)->index & (1 << i))
				ra(a);
			else
				pb(a, b);
			j++;
			if (ft_sort_check(a, len) == 0)
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

void	ft_radix2(t_stack **a, t_stack **b, t_stack **fake_a, int len)
{
	int	i;
	int	j;

	ft_index(a, fake_a);
	j = 0;
	i = 0;
	while (ft_sort_check(a, len))
	{
		while (j < len)
		{
			if ((*a)->index & (1 << i))
				ra(a);
			else
				pb(a, b);
			j++;
		}
		i++;
		j = 0;
		while ((*b))
			pa(a, b);
	}
}

void	ft_print_list(t_stack **list_head, char ab)
{
	t_stack	*print_stack;

	if (ab == 'a')
		ft_printf("stack a: ");
	else if (ab == 'b')
		ft_printf("stack b: ");
	print_stack = (*list_head);
	while (print_stack != NULL)
	{
		ft_printf("%i -> ", print_stack->data);
		print_stack = print_stack->next;
	}
	if (print_stack == NULL)
		ft_printf("NULL\n");
}

/*void	ft_chunk(t_stack **a, t_stack **b, t_stack **fake_a, int len)
{
	size_t	chunk;
	int		j;
	size_t	bigg;
	int		r;

	j = 0;
	r = 0;
	ft_index(a, fake_a);
	chunk = 30;
	while ((*a)->next)
	{
		while (j < len)
		{
			if ((*a)->next == NULL)
				break ;
			if ((*a)->index <= chunk)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		j = 0;
		chunk += chunk;
	}
	pb(a, b);
	bigg = ft_bigger_index(b);
	while ((*b))
	{
		while ((*b)->index != bigg)
		{
			if (r == 1)
				rrb(b);
			else
				rb(b);
		}
		pa(a, b);
		if ((*b) != NULL)
		{
			bigg = ft_bigger_index(b);
			r = ft_find_best_index(b, ft_len(b), bigg);
		}
	}
}*/
