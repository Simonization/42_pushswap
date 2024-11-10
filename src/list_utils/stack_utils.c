/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:39:22 by slangero          #+#    #+#             */
/*   Updated: 2024/11/05 15:26:29 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	stack_is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
			if (stack->value > stack->next->value)
				return (false);
			stack = stack->next;
	}
	return (true);
}

int		get_stack_size(t_node *stack)
{
	int    size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

t_node  *find_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*current_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	current_node = stack;
	while(current_node)
	{
		if(current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

t_node  *find_max_node(t_node *stack)
{
	t_node	*max_node;
	t_node	*current_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	current_node = stack;
	while(current_node)
	{
		if(current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}
