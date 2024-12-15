/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_init_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:13:25 by slangero          #+#    #+#             */
/*   Updated: 2024/12/13 17:25:12 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node	*find_target_in_a(t_node *a, t_node *b)
{
	t_node	*tmp_a;
	t_node	*target;
	int		closest_bigger;

	tmp_a = a;
	target = NULL;
	// First look for the closest bigger number in B
	while (a)
	{
		if (a->value > b->value && (!target || a->value < closest_bigger))
		{
			closest_bigger = a->value;
			target = a;
		}
		a = a->next;
	}
	
	// If no bigger number was found, find the biggest number in B
	// This means our number should go at the bottom of sorted sequence
	if (!target)
		target = find_min_node(tmp_a);
		
	return (target);
}

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	while (stack_b)
	{
		stack_b->target_node = find_target_in_a(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

static void	cost_analysis_b(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);

	while (stack_b)
	{
		// Calculate cost to rotate stack B (cost to get this number to top)
		cost_b = stack_b->pos;
		if (!stack_b->upper_median)
			cost_b = len_b - stack_b->pos;

		// Calculate cost to rotate stack A (cost to get target position to top)
		cost_a = stack_b->target_node->pos;
		if (!stack_b->target_node->upper_median)
			cost_a = len_a - stack_b->target_node->pos;

		// If we can rotate both stacks in the same direction
		if ((stack_b->upper_median && stack_b->target_node->upper_median) ||
			(!stack_b->upper_median && !stack_b->target_node->upper_median))
		{
			// Use the larger of the two costs since we can do them together
			stack_b->cost = (cost_a >= cost_b) ? cost_a : cost_b;
		}
		else
		{
			// If rotating in opposite directions, we must add the costs
			stack_b->cost = cost_a + cost_b;
		}

		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_b(stack_a, stack_b);
	cost_analysis_b(stack_a, stack_b);
	set_cheapest(stack_b);
}