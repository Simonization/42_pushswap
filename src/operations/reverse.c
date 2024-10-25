/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:50:19 by slangero          #+#    #+#             */
/*   Updated: 2024/10/24 19:19:54 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_node **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

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
	ft_putstr("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr("rrr\n");
}
