/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:38:28 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/25 10:50:50 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(struct stack** stack_a)
{
	ft_append(stack_a, (*stack_a)->data);
	ft_pop(stack_a);
	write(1, "ra\n", 3);
}

void	rb(struct stack** stack_b)
{
	ft_append(stack_b, (*stack_b)->data);
	ft_pop(stack_b);
	write(1, "rb\n", 3);
}

void	rr(struct stack** stack_a, struct stack** stack_b)
{
	ft_append(stack_a, (*stack_a)->data);
	ft_pop(stack_a);
	ft_append(stack_b, (*stack_b)->data);
	ft_pop(stack_b);
	write(1, "rr\n", 3);
}
