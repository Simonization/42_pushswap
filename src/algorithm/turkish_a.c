/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:07:54 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:27 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_position_cost_a(t_node *node, int stack_size)
{
	if (node->upper_median)
		return (node->pos);
	return (stack_size - node->pos);
}

int	get_combined_cost_a(int cost_a, int cost_b,
			t_node *node_a, t_node *target)
{
	bool	same_direction;

	same_direction = (node_a->upper_median && target->upper_median)
		|| (!node_a->upper_median && !target->upper_median);
	if (same_direction)
	{
		if (cost_a >= cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_a)
	{
		cost_a = get_position_cost_a(stack_a, len_a);
		cost_b = get_position_cost_a(stack_a->target_node, len_b);
		stack_a->cost = get_combined_cost_a(cost_a, cost_b,
				stack_a, stack_a->target_node);
		stack_a = stack_a->next;
	}
}

t_node	*find_target_in_b(t_node *a, t_node *b)
{
	t_node	*tmp_b;
	t_node	*target;
	int		closest_smaller;

	tmp_b = b;
	target = NULL;
	while (b)
	{
		if (b->value < a->value && (!target || b->value > closest_smaller))
		{
			closest_smaller = b->value;
			target = b;
		}
		b = b->next;
	}
	if (!target)
		target = find_max_node(tmp_b);
	return (target);
}
