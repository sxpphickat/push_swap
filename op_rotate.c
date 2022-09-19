/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:38:28 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/19 11:22:56 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	ft_append(stack_b, (*stack_b)->data, (*stack_b)->index);
	ft_pop(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
	ft_append(stack_b, (*stack_b)->data, (*stack_b)->index);
	ft_pop(stack_b);
	write(1, "rr\n", 3);
}

void	fra(t_stack **stack_a)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
}
