/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:40:40 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 19:43:46 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*node_new(int nb)
{
	t_node	*node_new;

	node_new = malloc(sizeof(t_node));
	if (!node_new)
		return (NULL);
	node_new->value = nb;
	node_new->pos = 0;
	node_new->cost = 0;
	node_new->upper_median = false;
	node_new->cheapest = false;
	node_new->target_node = NULL;
	node_new->next = NULL;
	node_new->prev = NULL;
	node_new->next = NULL;
	return (node_new);
}

t_node	*stack_add(t_node *stack, t_node *node_new)
{
	t_node	*last;

	if (!node_new)
		return (NULL);
	if (!stack)
		return (node_new);
	last = get_last_node(stack);
	last->next = node_new;
	node_new->prev = last;
	return (stack);
}
