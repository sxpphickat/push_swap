/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/19 14:58:56 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_decide(t_stack *stack_a, t_stack *stack_b, t_stack *fake_a, int len)
{
	t_stack	*fake_b;

	fake_b = NULL;
	if (!ft_sort_check(&stack_a, 1))
	{
		ft_free(&stack_a, &stack_b, &fake_a, &stack_b);
		return ;
	}
	if (len <= 5)
		ft_small(&stack_a, &stack_b, len);
	else if (len <= 50)
	{
		ft_fake_sort(&fake_a, &fake_b, len);
		ft_radix2(&stack_a, &stack_b, &fake_a, len);
	}
	else
	{
		ft_fake_sort(&fake_a, &fake_b, len);
		ft_radix(&stack_a, &stack_b, &fake_a);
		ft_pt2(&stack_a, &stack_b);
	}
	ft_free(&stack_a, &stack_b, &fake_a, &fake_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*fake_a;
	int		len;
	int		ret;
	char **matrix;
	char **temp;

	len = argc - 1;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		temp = matrix;
		len = 0;
		while (temp[len])
			len++;
		len--;
	}
	else
		matrix = argv;
	ft_printf("%i\n", len);
//		argv = ft_split(argv[1], ' ');
//	ft_printf("%s\n", matrix[0]);
	fake_a = NULL;
	stack_a = NULL;
	stack_b = NULL;
	ret = ft_create_x(&stack_a, matrix, len);
	ft_create_x(&fake_a, matrix, len);
	len++;
	if (ret == 1 || ft_repeat_check(&stack_a))
		return (write(2, "Error\n", 6));
	ft_decide(stack_a, stack_b, fake_a, len);
	return (0);
}

//ft_print_stacks(&stack_a, &stack_b);
