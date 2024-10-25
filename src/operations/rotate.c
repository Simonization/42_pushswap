/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:31 by slangero          #+#    #+#             */
/*   Updated: 2024/10/24 19:20:05 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}


void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr\n");
}
