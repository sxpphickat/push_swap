/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/05 13:56:07 by vipereir         ###   ########.fr       */
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

void	ft_create_x(struct s_stack **stack_a, char *argv[], int len);
void	ft_print_list(struct s_stack **list_head, char ab);
void ft_print_stacks(struct s_stack **stack_a, struct s_stack **stack_b);
void	fsa(struct s_stack **stack_a);
void	fra(struct s_stack **stack_a);
int	ft_sort_check(struct s_stack **stack_a, int	len);
void	ft_sort(struct s_stack **stack_a, struct s_stack **stack_b, int	len);
void	ft_fake_sort(struct s_stack **stack_a, struct s_stack **stack_b, int	len);
int	ft_repeat_check(struct s_stack **stack_a);
int		ft_smaller(struct s_stack **stack_a);
int		ft_bigger(struct s_stack **stack_a);
int		ft_find_best(struct s_stack **stack_a, int len, int find);
void	ft_super_sort(struct s_stack **stack_a, struct s_stack **stack_b, int len);
int	ft_check_left_sort(struct s_stack **stack_a, int pivot);
int		ft_last(struct s_stack **stack_a);
int	get_pivot(struct s_stack **stack_a);
int    ft_max_value(struct s_stack **list);
void    ft_concat(struct s_stack **stack_a, struct s_stack **stack_b);
void	ft_index(struct s_stack **a, struct s_stack **f);
int		ft_len(struct s_stack **x);
void	ft_radix(struct s_stack **a, struct s_stack **b,struct s_stack **fake_a, int len);
void	ft_five(struct s_stack **a, struct s_stack **b, int len);
void	ft_three(struct s_stack **a);
void	ft_small(struct s_stack **a, struct s_stack **b, int len);

unsigned int		ft_bigger_index(struct s_stack **stack_a);
int		ft_find_best_index(struct s_stack **stack_a, int len, unsigned int find);
unsigned int		ft_smaller_index(struct s_stack **stack_a);
unsigned int		ft_smallerb_index(struct s_stack **stack_a, unsigned int better);

#endif
