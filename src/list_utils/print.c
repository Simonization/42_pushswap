/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:06:36 by slangero          #+#    #+#             */
/*   Updated: 2024/11/11 19:13:51 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	printf("A B\n");
	printf("---\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			printf("%i", stack_a->value);
		else
			printf(" ");
		if (stack_a)
			stack_a = stack_a->next;
		printf(" ");
		if (stack_b)
			printf("%i", stack_b->value);
		else
			printf(" ");
		if (stack_b)
			stack_b = stack_b->next;
		printf("\n");
	}
}
