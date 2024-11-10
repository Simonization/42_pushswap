/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:31 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 16:01:54 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}


void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate_both(t_node	**stack_a,
					t_node	**stack_b,
					t_node	*cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	current_pos(*stack_a);
	current_pos(*stack_b);
}