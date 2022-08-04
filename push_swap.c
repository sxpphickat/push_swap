/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:19:15 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/04 16:15:07 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//stack

struct stack_node {
	int					data;
	struct stack_node*	next;
};

struct stack_node*	new_node(int data)
{
	struct stack_node*	stack_node;

	stack_node = malloc(sizeof(struct stack_node));
	stack_node->data = data;
	stack_node->next = NULL;
	return (stack_node);
}

int	ft_is_empty(struct stack_node* root)
{
	return (!root);
}

void ft_push(struct stack_node** root, int data)
{
	struct stack_node*	stack_node;

	stack_node = new_node(data);
	stack_node->next = *root;
	*root = stack_node;
	printf("%d pushed to stack\n", data);
}

int ft_pop(struct stack_node** root)
{
	struct	stack_node*	temp;
	int		popped;

	if (ft_is_empty(*root))
		return (INT_MIN);
	temp = *root;
	*root = (*root)->next;
	popped = temp->data;
	free(temp);
	return (popped);
}

int	ft_peek(struct stack_node* root)
{
	if (ft_is_empty(root))
		return (INT_MIN);
	return (root->data);
}

int	main(void)
{
	struct stack_node*	root;

	root = NULL;
	ft_push(&root, 10);
	ft_push(&root, 20);
	ft_push(&root, 30);
	ft_push(&root, 40);
	ft_push(&root, 50);
	ft_push(&root, 60);

	while (root != NULL)
	{
		printf("output: %d", root->data);
		root = root->next;
	}

	return (0);
}
