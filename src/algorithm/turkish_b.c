/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:13:25 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:39:39 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_position_cost_b(t_node *node, int stack_size)
{
	if (node->upper_median)
		return (node->pos);
	return (stack_size - node->pos);
}

int	get_combined_cost_b(int cost_a, int cost_b,
			t_node *node_b, t_node *target)
{
	bool	same_direction;

	same_direction = (node_b->upper_median && target->upper_median)
		|| (!node_b->upper_median && !target->upper_median);
	if (same_direction)
	{
		if (cost_a >= cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	cost_analysis_b(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_b)
	{
		cost_b = get_position_cost_b(stack_b, len_b);
		cost_a = get_position_cost_b(stack_b->target_node, len_a);
		stack_b->cost = get_combined_cost_b(cost_a, cost_b,
				stack_b, stack_b->target_node);
		stack_b = stack_b->next;
	}
}

t_node	*find_target_in_a(t_node *a, t_node *b)
{
	t_node	*tmp_a;
	t_node	*target;
	int		closest_bigger;

	tmp_a = a;
	target = NULL;
	while (a)
	{
		if (a->value > b->value && (!target || a->value < closest_bigger))
		{
			closest_bigger = a->value;
			target = a;
		}
		a = a->next;
	}
	if (!target)
		target = find_min_node(tmp_a);
	return (target);
}
