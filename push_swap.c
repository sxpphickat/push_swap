/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/29 16:21:22 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack


void	ft_create_x(struct stack** stack_a, char *argv[], int len)
{
	while (len >= 1)
		ft_push(stack_a, ft_atoi(argv[len--])); // tirar atoi;
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
			ft_printf("%i", temp_a->data);
			temp_a = temp_a->next;
		}
		write(1, "   ", 3);
		if (temp_b != NULL)
		{
			ft_printf("%i", temp_b->data);
			temp_b = temp_b->next;
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	write(1, "-  -\n", 5);
	write(1, "a  b\n", 5);
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
    struct stack    **aux;
    int max;

    aux = list;
    max = 0;
    while (*aux != NULL)
    {
        if ((*aux)->data > max)
            max = (*aux)->data;
        aux = &(*aux)->next;
    }
    return (max);
}

void    ft_concat(struct stack** stack_a, struct stack** stack_b)
{
    int    small;
    int a_max;

    a_max = ft_max_value(stack_a);
    if ((*stack_a)->data > (*stack_b)->data)
        small = (*stack_b)->data;
    else
        small = (*stack_a)->data;
    while ((*stack_b) != NULL)
    {
        if ((*stack_a)->data < (*stack_b)->data)
        {
            if((*stack_b)->data > a_max)
            {
                a_max = (*stack_a)->data;
                while ((*stack_a)->data != small)
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
    while ((*stack_a)->data != small)
            ra(stack_a);
}

int		ft_next(struct stack** a, int better)
{
	struct stack* temp;
	int	small;

	temp = (*a);
	while(temp->next != NULL)
	{
		if (temp->data < small && temp->data > better)
			small = temp->data;
		temp = temp->next;
	}
	return(small);
}

#include <stdio.h>
#include <signal.h>

void	ft_index(struct stack** a, int len)
{
	int	smaller;
	struct stack* temp;
	struct stack* head;
	int	i;

	(void)len;
	i = 1;
	temp = (*a);
	head = (*a);
	smaller = ft_smaller(a);
	while (i <= len)
	{
		while (temp->data != smaller && temp->next)
			temp = temp->next;
		temp->index = i;
		smaller = ft_next(a, smaller);
		temp = head;
		i++;
		//ft_printf("a"); // kkkkkkkkkkkk só funciona se tiver o printf;
	}
}

void	ft_radix(struct stack** a, struct stack** b, int len)
{
	int	i;
	int	j;
	int	bl;
//	int	big;

//	big = ft_bigger(a);
	j = 0;
	i = 0;
	bl = 0;
	(void)len;
	while (i < 7)
	{
		while (j < len)
		{
			if ((*a)->data & (1 << i))
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while ((*b))
			pa(a, b);
		j = 0;
		i++;
	}
	if (ft_last(a) < 0)
	{
		while (ft_last(a) < 0)
		{
			rra(a);
			pb(a, b);
		}
		ft_concat(a, b);
	}
}

int	main(int argc, char *argv[])
{
	struct stack*	stack_a;
	struct stack*	stack_b;
	int				len;

	len = argc - 1;
	if (argc < 2)
		return (0);

	stack_a = NULL;
	stack_b = NULL;
	ft_create_x(&stack_a, argv, len);
	if (ft_repeat_check(&stack_a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_print_stacks(&stack_a, &stack_b);
	ft_printf("------------------------\n");
	//ft_radix(&stack_a, &stack_b, len);
	ft_index(&stack_a, len);
	ft_printf("i: %i\n", stack_a->index);
	ft_printf("i: %i\n", stack_a->next->index);
	ft_printf("i: %i\n", stack_a->next->next->index);
	ft_printf("i: %i\n", stack_a->next->next->next->index);
	ft_printf("i: %i\n", stack_a->next->next->next->next->index);
	ft_printf("i: %i\n", stack_a->next->next->next->next->next->index);

	ft_print_stacks(&stack_a, &stack_b);

	return (0);
}
