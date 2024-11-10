/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_init_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:13:25 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 16:17:14 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node			*current_a;
	t_node			*target_node;
	long			best_match_pos;

	while(stack_b)
	{
		best_match_pos = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value < stack_b->value
				&& current_a->value < best_match_pos)
			{
				best_match_pos = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_pos == LONG_MAX)
			stack_b->target_node = find_min_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_b(stack_a, stack_b);
}