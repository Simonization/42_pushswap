/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:03:18 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:25:51 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_large(stack_a, stack_b);
}

void	sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (top > middle && middle < bottom && bottom > top)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && bottom < top)
		ra(stack);
	else if (top < middle && middle > bottom && bottom > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && middle > bottom && bottom < top)
		rra(stack);
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = get_stack_size(*stack_a);
	if (len_a-- > 3)
	{
		pb(stack_b, stack_a);
	}
	if (len_a-- > 3)
	{
		pb(stack_b, stack_a);
	}
	while (len_a-- > 3)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_pos(*stack_a);
	min_on_top(stack_a);
}
