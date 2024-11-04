/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:03:18 by slangero          #+#    #+#             */
/*   Updated: 2024/11/01 20:04:37 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sort_three(t_node **stack)
{
    int top;
    int middle;
    int bottom;
    if (!*stack || !(*stack)->next || !(*stack)->next->next)
        return;
    top = (*stack)->value;
    middle = (*stack)->next->value;
    bottom = (*stack)->next->next->value;
    if (top > middle && middle < bottom && bottom > top)
        sa(stack);
    else if (top > middle && middle > bottom)
    {
        sa(stack);
        rra(stack);
    }
    else if (top > middle && middle < bottom && bottom < top)
        ra(stack);
    else if (top < middle && middle > bottom && bottom > top)
    {
        sa(stack);
        ra(stack);
    }
    else if (top < middle && middle > bottom && bottom < top)
        rra(stack);
}
