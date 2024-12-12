/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:00:51 by slangero          #+#    #+#             */
/*   Updated: 2024/12/11 13:00:54 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return;

	// Store the first two nodes
	first = *stack;
	second = first->next;

	// Update first node's next pointer and its new next's prev pointer
	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	// Reset second's prev pointer since it's becoming the head
	second->prev = NULL;

	// Link second to first
	second->next = first;
	first->prev = second;

	// Update stack head
	*stack = second;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
