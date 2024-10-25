/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:00:51 by slangero          #+#    #+#             */
/*   Updated: 2024/10/25 13:48:34 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->next == NULL)
	return ;
	tmp = stack->next
	stack->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack b);
	ft_putstr("ss\n");
}