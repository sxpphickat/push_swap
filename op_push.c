/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:37:19 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/31 14:07:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if ((*stack_b) == NULL)
		return ;
	ft_push(stack_a, (*stack_b)->data, (*stack_b)->index);
	ft_pop(stack_b);
	write(1, "pa\n", 3);
}

void	pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
	if ((*stack_a) == NULL)
		return ;
	ft_push(stack_b, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
	write(1, "pb\n", 3);
}
