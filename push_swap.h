/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/20 12:18:28 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack {
	long			data;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

void	ft_push(t_stack **head_ref, long data, size_t index);
void	ft_append(t_stack **head_ref, long new_data, size_t index);
void	ft_insert_after(t_stack *node, long new_data, size_t index);
void	ft_pop(t_stack **stack_x);
void	ft_free(t_stack **a, t_stack **b, t_stack **fake_a, t_stack **fake_b);

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

void	fpa(t_stack **stack_a, t_stack **stack_b);
void	fpb(t_stack **stack_a, t_stack **stack_b);
void	fra(t_stack **stack_a);
void	frra(t_stack **stack_a);

int		ft_create_x(t_stack **stack_a, char *argv[], int len);
int		ft_sort_check(t_stack **stack_a, int len);
void	ft_fake_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		ft_repeat_check(t_stack **stack_a);
int		ft_bigger(t_stack **stack_a);
int		ft_find_best(t_stack **stack_a, int len, long find);
int		ft_check_left_sort(t_stack **stack_a, int pivot);
void	ft_concat(t_stack **stack_a, t_stack **stack_b);
void	ft_index(t_stack **a, t_stack **f);
int		ft_len(t_stack **x);
void	ft_radix(t_stack **a, t_stack **b, t_stack **fake_a);
void	ft_five(t_stack **a, t_stack **b, int len);
void	ft_three(t_stack **a);
void	ft_small(t_stack **a, t_stack **b, int len);

size_t	ft_bigger_index(t_stack **stack_a);
int		ft_find_best_index(t_stack **stack_a, int len, size_t find);
size_t	ft_smaller_index(t_stack **stack_a);
size_t	ft_smallerb_index(t_stack **stack_a, size_t better);

void	ft_pt2(t_stack **a, t_stack **b);
int		ft_rev_sort_check(t_stack **stack_a, int len);
long	ft_smaller(t_stack **stack_a);

int		ftf(t_stack **a, t_stack **fa, char **argv, int argc);
void	ft_free_matrix(char **matrix);

#endif
