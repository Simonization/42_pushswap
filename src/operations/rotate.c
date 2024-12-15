/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:31 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 19:47:05 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	tail = get_last_node(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = tail;
	tail->next = first_node;
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

// static void	rotate(t_node **stack)
// {
// 	t_node	*tmp;
// 	t_node	*tail;
// 	tmp = *stack;
// 	*stack = (*stack)->next;
// 	tail = get_last_node(*stack);
// 	tmp->next = NULL;
// 	tail->next = tmp;
// }
// void	rotate_both(t_node	**stack_a,
// 					t_node	**stack_b,
// 					t_node	*cheapest_node)
// {
// 	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
// 		rr(stack_a, stack_b);
// 	current_pos(*stack_a);
// 	current_pos(*stack_b);
// }