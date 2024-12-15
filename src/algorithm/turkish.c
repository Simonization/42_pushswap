/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:18:52 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 18:55:34 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheap;
	bool	rotate_a;
	bool	rotate_b;

	cheap = get_cheapest(*stack_a);
	rotate_a = cheap->upper_median;
	rotate_b = cheap->target_node->upper_median;
	while (*stack_a != cheap && *stack_b != cheap->target_node
		&& rotate_a && rotate_b)
		rr(stack_a, stack_b);
	while (*stack_a != cheap && *stack_b != cheap->target_node
		&& !rotate_a && !rotate_b)
		rrr(stack_a, stack_b);
	while (*stack_a != cheap)
		rotate_a ? ra(stack_a) : rra(stack_a);
	while (*stack_b != cheap->target_node)
		rotate_b ? rb(stack_b) : rrb(stack_b);
	pb(stack_b, stack_a);
}

static void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheap;
	bool	rotate_b;
	bool	rotate_a;

	cheap = get_cheapest(*stack_b);
	rotate_b = cheap->upper_median;
	rotate_a = cheap->target_node->upper_median;
	while (*stack_b != cheap && *stack_a != cheap->target_node
		&& rotate_b && rotate_a)
		rr(stack_a, stack_b);
	while (*stack_b != cheap && *stack_a != cheap->target_node
		&& !rotate_b && !rotate_a)
		rrr(stack_a, stack_b);
	while (*stack_b != cheap)
		rotate_b ? rb(stack_b) : rrb(stack_b);
	while (*stack_a != cheap->target_node)
		rotate_a ? ra(stack_a) : rra(stack_a);
	pa(stack_a, stack_b);
}

static void	min_on_top(t_node **stack_a)
{
	while ((*stack_a)->value != find_min_node(*stack_a)->value)
	{
		if (find_min_node(*stack_a)->upper_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = get_stack_size(*stack_a);
	if (len_a-- > 3)
	{
		pb(stack_b, stack_a);
	}
	if (len_a-- > 3)
	{
		pb(stack_b, stack_a);
	}
	while (len_a-- > 3)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_pos(*stack_a);
	min_on_top(stack_a);
}
