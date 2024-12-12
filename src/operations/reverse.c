/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:50:19 by slangero          #+#    #+#             */
/*   Updated: 2024/12/11 12:57:30 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse(t_node **stack)
{
	t_node	*tail;
	t_node	*before_tail;

	if (!*stack || !(*stack)->next)
		return;
		
	// Get the last and second-to-last nodes
	tail = get_last_node(*stack);
	before_tail = get_penultimate_node(*stack);
	
	// Update the second-to-last node
	before_tail->next = NULL;
	
	// Update the old tail's pointers
	tail->prev = NULL;
	tail->next = *stack;
	
	// Update the old head's prev pointer
	(*stack)->prev = tail;
	
	// Make tail the new head
	*stack = tail;
}

void	rra(t_node **stack_a)
{
	reverse(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **stack_b)
{
	reverse(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
