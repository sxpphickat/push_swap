/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_base_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:53:53 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/14 14:42:48 by vipereir         ###   ########.fr       */
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

size_t	ft_pow(size_t	nb, int	pow)
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

	three = 0;
	while (dec > 0)
	{
		three += dec % 3;
		three *= 10;
		dec /= 3;
	}
	three /= 10;
	//three /= 10; // divide por 10 e ja estou pegando a ultima casa;
	return (three);
}

int	main(void)
{
	printf("%zu\n", ft_dec_to_3(99));
	printf("%zu\n", size_three(99));
	printf("%zu\n", ft_pow(10, 10));
	return (0);
}

/*void	ft_radix_base_3(t_stack **a, t_stack **b, t_stack **fake_a, int len)
{
	int	i;
	int	j;
	int	big;

	ft_index(a, fake_a);
	j = 0;
	i = 0;
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
}*/
