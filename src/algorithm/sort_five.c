// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort_five.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/01 20:05:52 by slangero          #+#    #+#             */
// /*   Updated: 2024/11/01 21:35:02 by slangero         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pushswap.h"

// static int find_min_position(t_node *stack)
// {
//     int min;
//     int position;
//     int min_pos;
    
//     if (!stack)
//         return (-1);
//     min = INT_MAX;
//     position = 0;
//     min_pos = 0;
//     while (stack)
//     {
//         if (stack->value < min)
//         {
//             min = stack->value;
//             min_pos = position;
//         }
//         stack = stack->next;
//         position++;
//     }
//     return (min_pos);
// }

// static void push_min_to_b(t_node **stack_a, t_node **stack_b, int stack_size)
// {
//     int min_pos;
    
//     min_pos = find_min_position(*stack_a);
//     // If minimum is in the upper half, use ra
//     if (min_pos <= stack_size / 2)
//     {
//         while (min_pos > 0)
//         {
//             ra(stack_a);
//             min_pos--;
//         }
//     }
//     // If minimum is in the lower half, use rra
//     else
//     {
//         while (min_pos < stack_size)
//         {
//             rra(stack_a);
//             min_pos++;
//         }
//     }
//     pb(stack_a, stack_b);
// }

// void    sort_five(t_node **stack_a, t_node **stack_b)
// {
//     int size;
    
//     size = get_stack_size(*stack_a);
//     if (size < 4)
//         return sort_three(stack_a);
        
//     // Push smallest two numbers to stack_b
//     push_min_to_b(stack_a, stack_b, size);
//     size--;
//     push_min_to_b(stack_a, stack_b, size);
    
//     // Sort remaining three numbers
//     sort_three(stack_a);
    
//     // Push back the two smallest numbers
//     pa(stack_a, stack_b);
//     pa(stack_a, stack_b);
// }