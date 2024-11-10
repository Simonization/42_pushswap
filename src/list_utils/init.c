/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:12:27 by slangero          #+#    #+#             */
/*   Updated: 2024/11/10 16:08:09 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*init_stack_a(int argc, char **argv)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL, argv);
		if (i == 1)
			stack_a = node_new((int)nb);
		else
			stack_add(stack_a, node_new((int)nb));
		i++;
	}
	return (stack_a);
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
						char	stack_name)
{
	while (*stack != top_node)
	{
		if(stack_name == 'a')
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