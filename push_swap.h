/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/14 14:59:12 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				data;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

void	ft_push(t_stack **head_ref, int data, size_t index);
void	ft_append(t_stack **head_ref, int new_data, size_t index);
void	ft_insert_after(t_stack *node, int new_data, size_t index);
void	ft_pop(t_stack **stack_x);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_create_x(t_stack **stack_a, char *argv[], int len);
void	ft_print_list(t_stack **list_head, char ab);
void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b);
void	fsa(t_stack **stack_a);
void	fra(t_stack **stack_a);
int		ft_sort_check(t_stack **stack_a, int len);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int len);
void	ft_fake_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		ft_repeat_check(t_stack **stack_a);
int		ft_smaller(t_stack **stack_a);
int		ft_bigger(t_stack **stack_a);
int		ft_find_best(t_stack **stack_a, int len, int find);
void	ft_super_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		ft_check_left_sort(t_stack **stack_a, int pivot);
int		ft_last(t_stack **stack_a);
int		get_pivot(t_stack **stack_a);
int		ft_max_value(t_stack **list);
void	ft_concat(t_stack **stack_a, t_stack **stack_b);
void	ft_index(t_stack **a, t_stack **f);
int		ft_len(t_stack **x);
void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a, int len);
void	ft_five(t_stack **a, t_stack **b, int len);
void	ft_three(t_stack **a);
void	ft_small(t_stack **a, t_stack **b, int len);

size_t	ft_bigger_index(t_stack **stack_a);
int		ft_find_best_index(t_stack **stack_a, int len, size_t find);
size_t	ft_smaller_index(t_stack **stack_a);
size_t	ft_smallerb_index(t_stack **stack_a, size_t better);

void	ft_print_list(t_stack **list_head, char ab);
void	ft_print_stacks(t_stack **stack_a, t_stack **stack_b);
void	fsa(t_stack **stack_a);
void	fra(t_stack **stack_a);
int		ft_sort_check(t_stack **stack_a, int len);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int len);
void	ft_fake_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		ft_repeat_check(t_stack **stack_a);
int		ft_smaller(t_stack **stack_a);
int		ft_bigger(t_stack **stack_a);
int		ft_find_best(t_stack **stack_a, int len, int find);
void	ft_super_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		ft_last(t_stack **stack_a);
int		ft_check_left_sort(t_stack **stack_a, int pivot);
int		get_pivot(t_stack **stack_a);
int		ft_max_value(t_stack **list);
void	ft_concat(t_stack **stack_a, t_stack **stack_b);
void	ft_index(t_stack **a, t_stack **f);
int		ft_len(t_stack **x);
void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a, int len);
void	ft_pt2(t_stack **a, t_stack **b);
void	ft_radix2(t_stack **a, t_stack **b, t_stack **fake_a, int len);
void	ft_chunk(t_stack **a, t_stack **b, t_stack **fake_a, int len);
void	ft_radix_base_3(t_stack **a, t_stack **b, t_stack **fake_a, int len);
int		ft_rev_sort_check(t_stack **stack_a, int len);
void	ft_pt2(t_stack **a, t_stack **b);
size_t	size_three(size_t dec);
size_t	ft_pow(size_t	nb, size_t	pow);
size_t	ft_dec_to_3(size_t dec);

#endif
