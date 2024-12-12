/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:39:22 by slangero          #+#    #+#             */
/*   Updated: 2024/12/11 13:06:29 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	stack_is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*current_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	current_node = stack;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;
	t_node	*current_node;

	printf("Finding max node in stack:\n");
	if (!stack)
	{
		printf("Stack is empty!\n");
		return (NULL);
	}
	max_node = stack;
	current_node = stack;
	while (current_node)
	{
		printf("Current value: %d\n", current_node->value);
		if (current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	printf("Max value found: %d\n", max_node->value);
	return (max_node);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*      debug    */

void print_stacks(t_node *stack_a, t_node *stack_b)
{
    printf("\nStack A:\n");
    while (stack_a)
    {
        printf("%d ", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("\nStack B:\n");
    while (stack_b)
    {
        printf("%d ", stack_b->value);
        stack_b = stack_b->next;
    }
    printf("\n\n");
}