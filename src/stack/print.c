/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:06:36 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 19:04:23 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	ft_printf("A B\n");
	ft_printf("---\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			ft_printf("%i", stack_a->value);
		else
			ft_printf(" ");
		if (stack_a)
			stack_a = stack_a->next;
		ft_printf(" ");
		if (stack_b)
			ft_printf("%i", stack_b->value);
		else
			ft_printf(" ");
		if (stack_b)
			stack_b = stack_b->next;
		ft_printf("\n");
	}
}
