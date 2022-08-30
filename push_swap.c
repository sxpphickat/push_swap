/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/30 16:45:40 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack


void	ft_create_x(struct stack** stack_a, char *argv[], int len)
{
	while (len >= 1)
		ft_push(stack_a, ft_atoi(argv[len--]), 0); // tirar atoi;
}

void	ft_print_list(struct stack** list_head, char ab)
{
	struct stack*	print_stack;

	if (ab == 'a')
		ft_printf("stack a: ");
	else if (ab == 'b')
		ft_printf("stack b: ");
	print_stack = (*list_head);
	while (print_stack != NULL)
	{
		ft_printf("%i -> ", print_stack->data);
		print_stack = print_stack->next;
	}
	if (print_stack == NULL)
		ft_printf("NULL\n");
}

void ft_print_stacks(struct stack** stack_a, struct stack** stack_b)
{
	struct stack*	temp_b;
	struct stack*	temp_a;

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

void	fsa(struct stack** stack_a)
{
	struct stack*	node_one;
	struct stack*	node_two;

	if ((*stack_a)->next == NULL)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
}

void	fra(struct stack** stack_a)
{
	ft_append(stack_a, (*stack_a)->data, (*stack_a)->index);
	ft_pop(stack_a);
}

int	ft_sort_check(struct stack** stack_a, int	len)
{
	struct stack*	temp;
	int				i;

	i = 0;
	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
		{
			temp = temp->next;
			i++;
		}
		else
			return (1);
	}
	if (i == len - 1)
		return (0);
	return (1);
}

void	ft_sort(struct stack** stack_a, struct stack** stack_b, int	len)
{
	int		i;

	i = 0;
	(void)(*stack_b);
	while (ft_sort_check(stack_a, len))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
		ra(stack_a);
		i++;
		if (i == len - 1)
		{
			ra(stack_a);
			i = 0;
		}
	}
}

void	ft_fake_sort(struct stack** stack_a, struct stack** stack_b, int	len)
{
	int		i;

	i = 0;
	(void)(*stack_b);
	while (ft_sort_check(stack_a, len))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			fsa(stack_a);
		fra(stack_a);
		i++;
		if (i == len - 1)
		{
			fra(stack_a);
			i = 0;
		}
	}
}

int	ft_repeat_check(struct stack **stack_a)
{
	struct stack*	temp_stack;
	struct stack*	next;
	int				temp;

	temp_stack = (*stack_a);
	temp = temp_stack->data;
	if (temp_stack->next != NULL)
		temp_stack = temp_stack->next;
	else
		return(1);
	if (temp_stack->next != NULL)
		next = temp_stack->next;
	else
		next = NULL;
	while (temp_stack != NULL)
	{
		if (temp == temp_stack->data)
			return (1);
		else
			temp_stack = temp_stack->next;
		if (temp_stack == NULL)
		{
			if (next != NULL)
			{
				temp_stack = next->next;
				temp = next->data;
				next = temp_stack;
			}
		}
	}
	return (0);
}

int		ft_smaller(struct stack** stack_a)
{
	struct stack* temp;
	int	small;

	temp = (*stack_a);
	small = temp->data;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if (small > temp->data)
			small = temp->data;
	}
	return(small);
}

int		ft_bigger(struct stack** stack_a)
{
	struct stack* temp;
	int	big;

	temp = (*stack_a);
	big = temp->data;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if (big < temp->data) 
			big = temp->data;
	}
	return(big);
}

int		ft_find_best(struct stack** stack_a, int len, int find)
{
	struct stack* temp;
	int	movs;

	movs = 0;
	temp = (*stack_a);
	while(temp->data != find)
	{
		temp = temp->next;
		movs++;
	}
	if (movs > len / 2)
		return(1);
	else
		return (2);
}

void	ft_super_sort(struct stack** stack_a, struct stack** stack_b, int len)
{
	int	r;
	int	small;

	(void)stack_b;
	small = ft_smaller(stack_a);
	r = ft_find_best(stack_a, len, small);
	while ((*stack_a) != NULL)
	{
		while((*stack_a)->data != small)
		{
			if (r == 1)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		if ((*stack_a) != NULL)
		{
			small = ft_smaller(stack_a);
			r = ft_find_best(stack_a, len, small);
		}
	}
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b);
}

int		ft_last(struct stack** stack_a)
{
	struct stack *temp;

	temp = (*stack_a);
	while (temp->next)
		temp = temp->next;
	return (temp->data);
}


int	ft_check_left_sort(struct stack** stack_a, int	pivot)
{
	struct stack*	temp;

	temp = (*stack_a);
	if (temp->data == pivot)
		return (1);
	while (temp->data != pivot)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

int	get_pivot(struct stack** stack_a)
{
	struct stack*	temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			break;
	}
	return (temp->data);
}

int    ft_max_value(struct stack **list)
{
    struct stack	**aux;
    unsigned int	max;

    aux = list;
    max = 0;
    while (*aux != NULL)
    {
        if ((*aux)->index > max)
            max = (*aux)->index;
        aux = &(*aux)->next;
    }
    return (max);
}

void    ft_concat(struct stack** stack_a, struct stack** stack_b)
{
    unsigned int	small;
    unsigned int	a_max;

    a_max = ft_max_value(stack_a);
    if ((*stack_a)->index > (*stack_b)->index)
        small = (*stack_b)->index;
    else
        small = (*stack_a)->index;
    while ((*stack_b) != NULL)
    {
        if ((*stack_a)->index < (*stack_b)->index)
        {
            if((*stack_b)->index > a_max)
            {
                a_max = (*stack_a)->index;
                while ((*stack_a)->index != small)
                    ra(stack_a);
                pa(stack_a, stack_b);
                ra(stack_a);
            }
            else
                ra(stack_a);
        }
        else
        {
            pa(stack_a, stack_b);
            ra(stack_a);
        }
    }
    while ((*stack_a)->index != small)
            ra(stack_a);
}

void	ft_index(struct stack **a, struct stack** f)
{
	int	i;
	struct stack *temp;
	struct stack *tempf;

	temp = (*a);
	tempf = (*f);

	i = 0;
	while (tempf)
	{
		while (temp->data != tempf->data)
			temp = temp->next;
		temp->index = i;
		i++;
		temp = (*a);
		tempf = tempf->next;
	}
}

int		ft_len(struct stack** x)
{
	int	i;
	struct stack* temp;

	temp = (*x);
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_radix(struct stack** a, struct stack** b,struct stack** fake_a, int len)
{
	int	i;
	int	j;
	int	bl;

	ft_index(a, fake_a);
	j = 0;
	i = 0;
//	while (ft_sort_check(a, len))
	while ((*a))
	{
		len = ft_len(a);
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
		bl = ft_len(b);
		while (j < bl)
		{
			if ((*b)->index & (1 << i))
				pa(a, b);
			else
				rb(b);
			j++;
		}
		j = 0;
	}
	while((*b))
		pa(a, b);
}

int	main(int argc, char *argv[])
{
	struct stack*	stack_a;
	struct stack*	stack_b;
	struct stack*	fake_a;
	int				len;

	len = argc - 1;
	if (argc < 2)
		return (0);

	stack_a = NULL;
	stack_b = NULL;
	ft_create_x(&stack_a, argv, len);
	ft_create_x(&fake_a, argv, len);
	if (ft_repeat_check(&stack_a))
	{
		write(2, "Error\n", 6);
		return (666);
	}
	//ft_print_stacks(&stack_a, &stack_b);
	//ft_printf("------------------------\n");
	//ft_print_stacks(&stack_a, &stack_b);
	ft_fake_sort(&fake_a, &fake_a, len);
//	ft_index(&stack_a, &fake_a);
	//ft_print_stacks(&stack_a, &stack_b);
	//ft_print_stacks(&fake_a, &stack_b);
	ft_radix(&stack_a, &stack_b, &fake_a, len);
	ft_print_stacks(&stack_a, &stack_b);

	return (0);
}
