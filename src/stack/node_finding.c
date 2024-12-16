/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:39:22 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:11:56 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*current_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	current_node = stack;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;
	t_node	*current_node;

	if (!stack)
	{
		return (NULL);
	}
	max_node = stack;
	current_node = stack;
	while (current_node)
	{
		if (current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

t_node	*get_cheapest(t_node *stack)
{
	t_node	*cheapest;
	int		min_cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
	min_cost = stack->cost;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
