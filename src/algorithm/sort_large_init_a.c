/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_init_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:23:21 by slangero          #+#    #+#             */
/*   Updated: 2024/12/13 17:16:22 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	current_pos(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->upper_median = true;
		else
			stack->upper_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_value(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = get_stack_size(stack) / 2;
	if (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->upper_median = true;
		else
			stack->upper_median = false;
	}
}

static t_node	*find_target_in_b(t_node *a, t_node *b)
{
	t_node	*tmp_b;
	t_node	*target;
	int		closest_smaller;

	tmp_b = b;
	target = NULL;
	// First look for the closest bigger number in B
	while (b)
	{
		if (b->value < a->value && (!target || b->value > closest_smaller))
		{
			closest_smaller = b->value;
			target = b;
		}
		b = b->next;
	}
	
	// If no bigger number was found, find the biggest number in B
	// This means our number should go at the bottom of sorted sequence
	if (!target)
		target = find_max_node(tmp_b);
		
	return (target);
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	if (!stack_b)
		return;

	while (stack_a)
	{
		stack_a->target_node = find_target_in_b(stack_a, stack_b);
		stack_a = stack_a->next;
	}
}

static void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);

	while (stack_a)
	{
		// Calculate cost to rotate stack A (cost to get this number to top)
		cost_a = stack_a->pos;
		if (!stack_a->upper_median)
			cost_a = len_a - stack_a->pos;

		// Calculate cost to rotate stack B (cost to get target position to top)
		cost_b = stack_a->target_node->pos;
		if (!stack_a->target_node->upper_median)
			cost_b = len_b - stack_a->target_node->pos;

		// If we can rotate both stacks in the same direction
		if ((stack_a->upper_median && stack_a->target_node->upper_median) ||
			(!stack_a->upper_median && !stack_a->target_node->upper_median))
		{
			// Use the larger of the two costs since we can do them together
			stack_a->cost = (cost_a >= cost_b) ? cost_a : cost_b;
		}
		else
		{
			// If rotating in opposite directions, we must add the costs
			stack_a->cost = cost_a + cost_b;
		}

		stack_a = stack_a->next;
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

void ft_printlst2(t_node *node)
{
	while(node)
	{
		if (node->target_node)
		{
			printf("value: %d\n", (node->target_node)->value);
		}
		else
		{
			printf("not found\n");
		}
		node = node->next;
	}
}

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	
	//print_stacks(stack_a, stack_b); /*    DEBUG   */
	set_target_a(stack_a, stack_b);
	//ft_printlst2(stack_a);
	//printf("check\n");
	cost_analysis_a(stack_a, stack_b);
	//printf("check\n");
	set_cheapest(stack_a);
}
