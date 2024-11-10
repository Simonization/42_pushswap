/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:23:21 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 15:25:56 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	current_pos(t_node *stack)
{
	int	i;
	int	median;
	
	id_t = 0;
	if(!stack)
		return;
	median = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->upper_median = true;
		else
			stack->upper_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node			*current_b;
	t_node			*target_node;
	long			best_match_pos;

	while(stack_a)
	{
		best_match_pos = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_pos)
			{
				best_match_pos = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_pos == LONG_MIN)
			stack_a->target_node = find_max_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->pos;
		if (!(stack_a->upper_median))
			stack_a->cost = len_a - (stack_a->pos);
		if (stack_a->target_node->upper_median)
			stack_a->cost += stack_a->target_node->pos;
		else
			stack_a->cost += len_b - (stack_a->target_node->pos);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_node	*stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return;
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

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
