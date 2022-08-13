/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/12 23:32:48 by sphh             ###   ########.fr       */
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
			temp_a = temp_a->next;
		}
		write(1, "  ", 2);
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

void	ft_sort(struct stack** stack_a, struct stack** stack_b, int	len)
{
	(void)(*stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_sa(stack_a, len);
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
	write(1, "\n", 1);
//	ft_push(&stack_b, 20);
	ft_create_x(&stack_a, argv, len);
	ft_print_stacks(&stack_a, &stack_b);
	ft_printf("------------------------\n");
	ft_sort(&stack_a, &stack_b, len);
	ft_print_stacks(&stack_a, &stack_b);

	return (0);
}



