/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:58:12 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/14 14:58:24 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
