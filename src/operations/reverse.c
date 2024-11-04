/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:50:19 by slangero          #+#    #+#             */
/*   Updated: 2024/10/27 15:49:18 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse(t_node **stack)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = get_last_node(*stack);
	before_tail = get_penultimate_node(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
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
