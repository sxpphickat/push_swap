/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:29:51 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/19 18:15:41 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_ck(char	*s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

int	ft_create_x(t_stack **stack_a, char *argv[], int len)
{
	int		ret;
	long	nb;

	ret = 0;
	while (len >= 0)
	{
		if ((ft_ck(argv[len])) == 1)
			ret = 1;
		nb = ft_atoi(argv[len--]);
		if (nb > 2147483647 || nb < -2147483648)
			ret = 1;
		ft_push(stack_a, nb, 0);
	}
	return (ret);
}

void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	write(1, "\n", 1);
	while (temp_a != NULL || temp_b != NULL)
	{
		if (temp_a != NULL)
		{
			ft_printf("%i -> %i", temp_a->data, temp_a->index);
			temp_a = temp_a->next;
		}
		write(1, "   ", 3);
		if (temp_b != NULL)
		{
			ft_printf("%i -> %i", temp_b->data, temp_b ->index);
			temp_b = temp_b->next;
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	write(1, "-  -\n", 5);
	write(1, "a  b\n", 5);
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
