/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:39:56 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 10:40:11 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
