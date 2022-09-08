/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/08 17:40:01 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*fake_a;
	int		len;

	len = argc - 1;
	if (argc < 2)
		return (0);
	fake_a = NULL;
	stack_a = NULL;
	stack_b = NULL;
	ft_create_x(&stack_a, argv, len);
	ft_create_x(&fake_a, argv, len);
	if (ft_repeat_check(&stack_a))
	{
		write(2, "Error\n", 6);
		return (666);
	}
	if (len <= 5)
		ft_small(&stack_a, &stack_b, len);
	else
	{
		ft_fake_sort(&fake_a, &fake_a, len);
		ft_radix(&stack_a, &stack_b, &fake_a, len);
	}
	ft_print_stacks(&stack_a, &stack_b);
	return (0);
}
