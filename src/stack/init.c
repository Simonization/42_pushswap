/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:17:27 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:40:42 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack_a(t_node **stack_a, char **av)
{
	long	nb;
	int		i;

	*stack_a = NULL;
	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (i == 0)
			*stack_a = node_new((int)nb);
		else
			stack_add(*stack_a, node_new((int)nb));
		i++;
	}
}

t_node	*init_stack_b(void)
{
	t_node	*stack_b;

	stack_b = NULL;
	return (stack_b);
}

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
