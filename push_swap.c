/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/23 15:09:06 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft/libft.h"

//stack

struct	stack {
	int		data;
	struct	stack* next;
};

void ft_push(struct stack** head_ref, int	data)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack)); //aloca espaço para o node;
	new_node->data = data; // coloca os dados dentro do node;
	new_node->next = (*head_ref); //novo node aponta para a cabeça;
	(*head_ref) = new_node; //a cabeça agr aponta para o node;
}

void ft_append(struct stack** head_ref, int	new_data)
{
	struct stack*	new_node;
	struct stack*	temp;

	temp = *head_ref;
	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data; // set o valor;
	new_node->next = NULL; //novo n´p agora ponta para NULL;
	if (temp == NULL)
	{
		temp = new_node;
		return ;
	}
	while (temp->next != NULL) //percorre a lista até o ultimo nó;
		temp = temp->next;
	temp->next = new_node; //o antigo ultimo agr aponta para o novo nó;
}

void ft_insert_after(struct stack*	node, int	new_data)
{
	struct stack*	new_node;

	new_node = (struct stack*)malloc(sizeof(struct stack));
	new_node->data = new_data;
	new_node->next = node->next;
	node->next = new_node;
}

void	ft_sa(struct stack** stack_a, int	len)
{
	struct stack*	node_one;
	struct stack*	node_two;

	if (len < 2)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sa\n", 3);
}

void	ft_sb(struct stack** stack_b, int	len)
{
	struct stack*	node_one;
	struct stack*	node_two;

	if (len < 2)
		return ;
	node_one = (*stack_b);
	node_two = (*stack_b)->next;
	*stack_b = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	write(1, "sb\n", 3);
}

void ft_ss(struct stack** stack_a, struct stack** stack_b, int len_a, int len_b)
{
	struct stack*	node_one;
	struct stack*	node_two;
	struct stack*	node_one_b;
	struct stack*	node_two_b;

	if (len_a < 2 || len_b < 2)
		return ;
	node_one = (*stack_a);
	node_two = (*stack_a)->next;
	*stack_a = node_two;
	node_one->next = node_two->next;
	node_two->next = node_one;
	node_one_b = (*stack_b);
	node_two_b = (*stack_b)->next;
	*stack_b = node_two_b;
	node_one_b->next = node_two_b->next;
	node_two_b->next = node_one_b;
	write(1, "ss\n", 3);
}

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

void	ft_pop(struct stack** stack_x)
{
	struct stack* temp;

	if ((*stack_x) == NULL)
		return ;
	temp = (*stack_x);
	(*stack_x) = temp->next;
	temp = NULL;      //deleta o conteudo;
	free(temp);
}

void ft_pa(struct stack** stack_a, struct stack** stack_b, int len_b)
{
	if ((*stack_b) == NULL)
		return ;
	if (len_b == 0)
		return ;
	ft_push(stack_a, (*stack_b)->data);
	ft_pop(stack_b);
	write(1, "pa\n", 3);
}

void ft_pb(struct stack** stack_a, struct stack** stack_b, int len_a)
{
	if ((*stack_a) == NULL)
		return ;
	if (len_a == 0)
		return ;
	ft_push(stack_b, (*stack_a)->data);
	ft_pop(stack_a);
	write(1, "pb\n", 3);
}

void ft_ra(struct stack** stack_a)
{
	ft_append(stack_a, (*stack_a)->data);
	ft_pop(stack_a);
	write(1, "ra\n", 3);
}

void ft_rb(struct stack** stack_b)
{
	ft_append(stack_b, (*stack_b)->data);
	ft_pop(stack_b);
	write(1, "rb\n", 3);
}

void ft_rr(struct stack** stack_a, struct stack** stack_b)
{
	ft_append(stack_a, (*stack_a)->data);
	ft_pop(stack_a);
	ft_append(stack_b, (*stack_b)->data);
	ft_pop(stack_b);
	write(1, "rr\n", 3);
}

void ft_rra(struct stack** stack_a)
{
	struct stack*	temp;
	struct stack*	temp_free;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_a, temp->next->data);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void ft_rrb(struct stack** stack_b)
{
	struct stack*	temp;
	struct stack*	temp_free;

	if ((*stack_b)->next == NULL)
		return ;
	temp = (*stack_b);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_b, temp->next->data);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void ft_rrr(struct stack** stack_a, struct stack** stack_b)
{
	struct stack*	temp;
	struct stack*	temp_free;
	struct stack*	temp_b;
	struct stack*	temp_free_b;

	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_a);
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_push(stack_a, temp->next->data);
	temp_free = temp->next;
	free(temp_free);
	temp->next = NULL;
	temp_b = (*stack_b);
	while (temp_b->next->next != NULL)
		temp_b = temp_b->next;
	ft_push(stack_b, temp_b->next->data);
	temp_free_b = temp_b->next;
	free(temp_free_b);
	temp_b->next = NULL;
	write(1, "rrr\n", 4);
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
		//	if (temp_a->data < 10)
		//		write(1, "    ", 4);
		//	else if (temp_a->data < 100)
		//		write(1, "   ", 3);
		//	else if (temp_a->data < 1000)
		//		write(1, "  ", 2);
		//	else
		//		write(1, " ", 1);

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
			ft_sa(stack_a, len);
		ft_ra(stack_a);
		i++;
		if (i == len - 1)
		{
			ft_ra(stack_a);
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
		if (small > temp->data && temp->data) 
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
		if (big < temp->data && temp->data) 
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
	int	bhead;

	bhead = (*stack_b)->data;
	(void)stack_b;
	small = ft_smaller(stack_a);
	r = ft_find_best(stack_a, len, small);
	while ((*stack_a) != NULL)
	{
		while((*stack_a)->data != small)
		{
			if (r == 1)
				ft_rra(stack_a);
			else
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b, len);
		if ((*stack_a) != NULL)
		{
			small = ft_smaller(stack_a);
			r = ft_find_best(stack_a, len, small);
		}
	}
	while ((*stack_b)->data != bhead)
		ft_pa(stack_a, stack_b, len);
}

void	ft_super_sort_b(struct stack** stack_a, struct stack** stack_b, int len)
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
				ft_rra(stack_a);
			else
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b, len);
		if ((*stack_a) != NULL)
		{
			small = ft_smaller(stack_a);
			r = ft_find_best(stack_a, len, small);
		}
	}
	while ((*stack_b) != NULL)
		ft_pa(stack_a, stack_b, len);
}

void	ft_divide(struct stack** stack_a, struct stack** stack_b, int	len)
{
	int	i;

	i = 1;
	ft_pb(stack_a, stack_b, len);
	while (i < len / 2)
	{
		ft_pb(stack_a, stack_b, len);
		if ((*stack_a) && (*stack_a)->next && 
				(*stack_b)->data > (*stack_b)->next->data && 
				(*stack_a)->data > (*stack_a)->next->data)
			ft_ss(stack_a, stack_b, len, len);
		else if ((*stack_b)->data > (*stack_b)->next->data)
			ft_sb(stack_b, len);
		else if ((*stack_a) && (*stack_a)->next && (*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a, len);
		i++;
	}
	i = 0;

	int	small_a = ft_smaller(stack_a);
	int	op = 1;
	while (ft_sort_check(stack_a, len / 2))
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_b)->data > (*stack_b)->next->data)
			ft_ss(stack_a, stack_b, len, len);
		else if ((*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a, len);
		else if ((*stack_b)->data > (*stack_b)->next->data)
			ft_sb(stack_b, len);
		if (op == 1)
			ft_rrr(stack_a, stack_b);
		else if (op == 0)
			ft_rr(stack_a, stack_b);
		i++;
		if (i == len / 2 - 1)
		{
			if (op == 0)
				ft_rrr(stack_a, stack_b);
			else if (op == 1)
				ft_rr(stack_a, stack_b);
			op = !op;
			i = 0;
		}
	}

}

void	ft_pushswap(struct stack** stack_a, struct stack** stack_b, int	len)
{
	ft_divide(stack_a, stack_b, len);

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

void	ft_quick_sort(struct stack** stack_a, struct stack** stack_b, int len)
{
	int	pivot;
	int	i;

	i = 0;
	pivot = ft_bigger(stack_a);
		ft_ra(stack_a);
		while ((*stack_a)->data != pivot)
		{
			if ((*stack_a)->data < pivot)
				ft_pb(stack_a, stack_b, len);
			else
				ft_ra(stack_a);
			if ((*stack_a)->data > (*stack_a)->next->data)
				ft_sa(stack_a, len);
		}
		while ((*stack_b) != NULL)
			ft_pa(stack_a, stack_b, len);
	ft_printf("%i\n", pivot);
	/*while (ft_sort_check(stack_a, len))
	{
		ft_rra(stack_a);
		pivot = get_pivot(stack_a);
		fpart = pivot;
		ft_ra(stack_a);
		while ((*stack_a)->data != fpart)
		{
			if ((*stack_a)->data < pivot)
				ft_pb(stack_a, stack_b, len);
			else
				ft_ra(stack_a);
		}
		while ((*stack_b) != NULL)
			ft_pa(stack_a, stack_b, len);
	}*/
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
	ft_pushswap(&stack_a, &stack_b, len);


	ft_print_stacks(&stack_a, &stack_b);

	return (0);
}
