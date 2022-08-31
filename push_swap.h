/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/30 09:46:03 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

struct	s_stack {
	int				data;
	unsigned int	index;
	struct s_stack	*next;
};

void	ft_push(struct s_stack **head_ref, int data, unsigned int index);
void	ft_append(struct s_stack **head_ref, int new_data, unsigned int index);
void	ft_insert_after(struct s_stack *node, int new_data, unsigned int index);
void	ft_pop(struct s_stack **stack_x);

void	sa(struct s_stack **stack_a);
void	sb(struct s_stack **stack_b);
void	ss(struct s_stack **stack_a, struct s_stack **stack_b);
void	pa(struct s_stack **stack_a, struct s_stack **stack_b);
void	pb(struct s_stack **stack_a, struct s_stack **stack_b);
void	ra(struct s_stack **stack_a);
void	rb(struct s_stack **stack_b);
void	rr(struct s_stack **stack_a, struct s_stack **stack_b);
void	rra(struct s_stack **stack_a);
void	rrb(struct s_stack **stack_b);
void	rrr(struct s_stack **stack_a, struct s_stack **stack_b);
#endif
