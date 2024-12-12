/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:19:10 by slangero          #+#    #+#             */
/*   Updated: 2024/12/11 12:51:44 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void    push(t_node **src, t_node **dest)
{
    t_node  *push_node;

    if (!*src)
        return ;
        
    // Save node to push and update src
    push_node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
        
    // Reset pushed node's prev pointer
    push_node->prev = NULL;
    
    // Handle destination
    if (!*dest)
    {
        // If dest is empty, make pushed node the only node
        *dest = push_node;
        push_node->next = NULL;
    }
    else
    {
        // Link pushed node to top of dest
        push_node->next = *dest;
        push_node->next->prev = push_node;
        *dest = push_node;
    }
}


// static void	push(t_node **src, t_node **dest)
// {
// 	t_node	*tmp;

// 	// if (*src == NULL)
// 	// 	return ;
// 	// tmp = (*src)->next;
// 	// (*src)->next = *dest;
// 	// *dest = *src;
// 	// *src = tmp;

// }

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}


void    pb(t_node **stack_b, t_node **stack_a)
{
    push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
}

// void pb(t_node **stack_a, t_node **stack_b)
// {
//     printf("pb: stack_a=%p (*stack_a=%p) stack_b=%p (*stack_b=%p)\n", 
//            (void*)stack_a, (void*)*stack_a, 
//            (void*)stack_b, (void*)*stack_b);
//     printf("pb: top value of stack_a: %d\n", (*stack_a)->value);
//     push(stack_a, stack_b);
//     printf("pb: After push: stack_a=%p (*stack_a=%p) stack_b=%p (*stack_b=%p)\n",
//            (void*)stack_a, (void*)*stack_a, 
//            (void*)stack_b, (void*)*stack_b);
//     ft_putstr_fd("pb\n", 1);
// }
