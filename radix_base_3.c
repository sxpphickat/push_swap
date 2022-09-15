/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_base_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:53:53 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 09:52:35 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

size_t	size_three(size_t dec)
{
	size_t	size;

	size = 0;
	while (dec > 0)
	{
		dec /= 3;
		size++;
	}
	return (size);
}

size_t	ft_pow(size_t	nb, size_t	pow)
{
	size_t pow_nb;

	pow_nb = nb;
	while (pow--)
		pow_nb *= nb;
	return (pow_nb);
}

size_t	ft_dec_to_3(size_t dec)
{
	size_t	three;
	size_t	pow;

	three = 0;
	three = ft_pow(10, size_three(dec));
	pow = three;
	while (dec > 0)
	{
		three += dec % 3 * pow;
		three /= 10;
		dec /= 3;
	}
	three /= 10;
	three--;
	return (three);
}
/*
void	ft_radix_base_3(t_stack **a, t_stack **b, t_stack **fake_a, int len)
{
	int	i;
	int	j;
	size_t	div;

	ft_index(a, fake_a);
	div = 1;
	j = 0;
	i = 5;
	while (i > 0)
	{
		len = ft_len(a);
		while (j < len)
		{
			if (ft_dec_to_3((*a)->index) / div % 10 == 2)
				ra(a);
			else if (ft_dec_to_3((*a)->index) / div % 10 == 1)
				pb(a, b);
			else if (ft_dec_to_3((*a)->index) / div % 10 == 0)
				pb(a, b);
			j++;
		}
		j = 0;
		i--;
		len = ft_len(b);
		div *= 10;
		while (j < len)
		{
			if (ft_dec_to_3((*b)->index) / div % 10 == 2)
				pa(a, b);
			else
				rb(b);
			j++;
		}
		j = 0;

//		while ((*b))
//			pa(a, b);
	}
}




 *		while (j < len)
		{
			if (ft_dec_to_3((*b)->index) / div % 10 == 1)
				pa(a, b);
			else
				rb(b);
			j++;
		}
		j = 0;
		while ((*b))
			pa(a, b);

 * */
