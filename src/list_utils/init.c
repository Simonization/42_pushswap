/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:12:27 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 17:52:35 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	init_stack_a(t_node **stack_a, /*int ac,*/ char **av)
{
    long		nb;
    int			i;

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

t_node	*get_last_node(t_node *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_node	*get_penultimate_node(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	prep_for_push(t_node	**stack,
						t_node	*top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->upper_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->upper_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
