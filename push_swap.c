/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 10:38:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_decide(t_stack *stack_a, t_stack *stack_b, t_stack *fake_a, int len)
{
	if (len <= 5)
		ft_small(&stack_a, &stack_b, len);
	else if (len <= 50)
	{
		ft_fake_sort(&fake_a, &fake_a, len);
		ft_radix2(&stack_a, &stack_b, &fake_a, len);
	}
	else
	{
		ft_fake_sort(&fake_a, &fake_a, len);
		ft_radix(&stack_a, &stack_b, &fake_a);
		ft_pt2(&stack_a, &stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*fake_a;
	int		len;
	int		ret;

	len = argc - 1;
	if (argc <= 2)
		return (0);
	fake_a = NULL;
	stack_a = NULL;
	stack_b = NULL;
	ret = ft_create_x(&stack_a, argv, len);
	ft_create_x(&fake_a, argv, len);
	if (ret == 1 || ft_repeat_check(&stack_a))
		return (write(2, "Error\n", 6));
	ft_decide(stack_a, stack_b, fake_a, len);
	return (0);
}

//ft_print_stacks(&stack_a, &stack_b);
