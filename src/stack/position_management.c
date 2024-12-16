/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:10:49 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:49 by slangero         ###   ########.fr       */
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

void	prep_for_push(t_node	**stack,
						t_node	*top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->upper_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->upper_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

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
