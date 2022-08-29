/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/29 10:30:07 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft/libft.h"

struct	stack {
	int		data;
	struct	stack* next;
};

void	ft_push(struct stack** head_ref, int	data);
void	ft_append(struct stack** head_ref, int	new_data);
void	ft_insert_after(struct stack*	node, int	new_data);
void	ft_pop(struct stack** stack_x);

void	sa(struct stack** stack_a);
void	sb(struct stack** stack_b);
void	ss(struct stack** stack_a, struct stack** stack_b);
void	pa(struct stack** stack_a, struct stack** stack_b);
void	pb(struct stack** stack_a, struct stack** stack_b);
void	ra(struct stack** stack_a);
void	rb(struct stack** stack_b);
void	rr(struct stack** stack_a, struct stack** stack_b);
void	rra(struct stack** stack_a);
void	rrb(struct stack** stack_b);
void	rrr(struct stack** stack_a, struct stack** stack_b);
