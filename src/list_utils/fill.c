/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:40:40 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 14:34:03 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*node_new(int nb)
{
	t_node	*node_new;

	node_new = malloc(sizeof(t_node));
	if(!node_new)
		return;
	node_new->value = nb;
	node_new->next = NULL;
	return (node_new);
}

t_node	*stack_add(t_node *stack, t_node *node_new)
{
	t_node	*last;
	
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = get_last_node(stack);
		last->next = node_new;
		return (node_new);
	}
}