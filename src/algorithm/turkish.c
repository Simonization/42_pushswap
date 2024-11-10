/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:18:52 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 16:08:57 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->upper_median && cheapest_node->target_node->upper_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->upper_median)
		&& !(cheapest_node->target_node->upper_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}

static void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

static void	min_on_top(t_node **stack_a)
{
	while ((*stack_a)->value != find_min_node(*stack_a)->value)
	{
		if (find_min_node(*stack_a)->upper_median)
			ra(stack_a);
		else
			rra(a);
	}
}

void    sort_large(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = get_stack_size(*stack_a);
	if (len_a-- > 3 && !stack_is_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_is_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (len_a-- > 3 && !stack_is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b)
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(a, b);		
	}
	current_pos(*stack_a);
	min_on_top(a);
}