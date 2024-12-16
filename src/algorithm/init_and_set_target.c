/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_set_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:23:21 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:24:47 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_b(stack_a, stack_b);
	cost_analysis_b(stack_a, stack_b);
	set_cheapest(stack_b);
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	if (!stack_b)
		return ;
	while (stack_a)
	{
		stack_a->target_node = find_target_in_b(stack_a, stack_b);
		stack_a = stack_a->next;
	}
}

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	while (stack_b)
	{
		stack_b->target_node = find_target_in_a(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_node	*stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
