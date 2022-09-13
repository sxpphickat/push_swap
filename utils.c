/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:29:51 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/13 12:03:41 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	ret;

	ret = 0;
	while (len >= 1)
	{
		if ((ft_ck(argv[len])) == 1)
			ret = 1;
		ft_push(stack_a, ft_atoi(argv[len--]), 0);
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

void	fsa(t_stack **stack_a)
{
	t_stack	*node_one;
	t_stack	*node_two;

	if ((*stack_a)->next == NULL)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
}

void	fra(t_stack **stack_a)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
}
