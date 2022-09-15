/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:29:47 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 11:33:37 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **a, t_stack **b, t_stack **fake_a)
{
	while ((*a))
		ft_pop(a);
	while ((*b))
		ft_pop(b);
	while ((*fake_a))
		ft_pop(fake_a);
}
