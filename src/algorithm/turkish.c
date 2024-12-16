/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:18:52 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:36:02 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_until_top(t_node **stack, t_node *node,
	bool is_median, char stack_name)
{
	while (*stack != node)
	{
		if (is_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	min_on_top(t_node **stack_a)
{
	t_node	*min;

	min = find_min_node(*stack_a);
	rotate_until_top(stack_a, min, min->upper_median, 'a');
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
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
	rotate_until_top(stack_a, cheap, rotate_a, 'a');
	rotate_until_top(stack_b, cheap->target_node, rotate_b, 'b');
	pb(stack_b, stack_a);
}

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
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
	rotate_until_top(stack_b, cheap, rotate_b, 'b');
	rotate_until_top(stack_a, cheap->target_node, rotate_a, 'a');
	pa(stack_a, stack_b);
}
