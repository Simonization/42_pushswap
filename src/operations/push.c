/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:19:10 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 19:48:24 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

// static void	push(t_node **src, t_node **dest)
// {
// 	t_node	*tmp;
// 	// if (*src == NULL)
// 	// 	return ;
// 	// tmp = (*src)->next;
// 	// (*src)->next = *dest;
// 	// *dest = *src;
// 	// *src = tmp;
// }
// void pb(t_node **stack_a, t_node **stack_b)
// {
//     printf("pb: top value of stack_a: %d\n", (*stack_a)->value);
//     push(stack_a, stack_b);
//     ft_putstr_fd("pb\n", 1);
// }