/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:59:59 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/15 12:54:21 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "lib/libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				pos;
	int				above_median;
	int				min_mov;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	print_error(char **args);
long	ft_atol(char *str);
int		error_int(char **argv);
int		error_syntax(char **argv);
int		error_dup(char **argv);
void	free_args(char **arguments);

void	fill_stack(t_stack **a, char **argv);
void	ft_free_stack(t_stack **stack);
t_stack	*ft_last_node(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*max_node(t_stack *stack);
t_stack	*min_node(t_stack *stack);

void	sort_three(t_stack **a);
void	set_pos(t_stack *stack);
t_stack	*get_best_min_mov(t_stack *stack);
void	best_min_move_on_top(t_stack **stack, t_stack *best_min_node, int a);
void	min_on_top(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	set_min_mov(t_stack *a, t_stack *b);

void	sa(t_stack **a, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b, int check);
void	pa(t_stack **b, t_stack **a, int check);
void	pb(t_stack **a, t_stack **b, int check);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b, int check);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b, int check);

#endif
