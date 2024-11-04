/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:04 by slangero          #+#    #+#             */
/*   Updated: 2024/11/01 19:55:08 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void free_stack(t_node **stack)
{
    t_node *tmp;

    if (!stack || !(*stack))
        return;
    
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void exit_error(t_node **stack_a, t_node **stack_b, char **argv)
{
    if (argv && *argv)
    {
        while (*argv)
        {
            free(*argv);
            argv++;
        }
        free(argv);
    }
    free_stack(stack_a);
    free_stack(stack_b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}