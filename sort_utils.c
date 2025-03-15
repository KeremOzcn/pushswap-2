/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:55:29 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/15 12:57:25 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	max = max_node(*a)->num;
	if ((*a)->num == max)
		ra(a, 0);
	else if ((*a)->next->num == max)
		rra(a, 0);
	if ((*a)->next->num < (*a)->num)
		sa(a, 0);
}

void	set_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

t_stack	*get_best_min_mov(t_stack *stack)
{
	int		min_mov;
	t_stack	*node_min_mov;

	if (!stack)
		return (NULL);
	min_mov = INT_MAX;
	while (stack)
	{
		if (stack->min_mov < min_mov)
		{
			min_mov = stack->min_mov;
			node_min_mov = stack;
		}
		stack = stack->next;
	}
	return (node_min_mov);
}

void	best_min_move_on_top(t_stack **stack, t_stack *best_min_node, int a)
{
	while (*stack != best_min_node)
	{
		if (best_min_node->above_median)
		{
			if (a)
				ra(stack, 0);
			else
				rb(stack, 0);
		}
		else
		{
			if (a)
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;
	int		index;
	int		len;

	set_pos(*a);
	min = min_node(*a);
	index = min->pos;
	len = stack_len(*a);
	if ((*a)->num == min->num)
		return ;
	if (index <= len / 2)
	{
		while ((*a)->num != min->num)
			ra(a, 0);
	}
	else
	{
		while ((*a)->num != min->num)
			rra(a, 0);
	}
}
