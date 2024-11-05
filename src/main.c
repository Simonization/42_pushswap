/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:27:03 by slangero          #+#    #+#             */
/*   Updated: 2024/11/05 13:13:33 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sort_stack(t_node **stack_a, t_node **stack_b)
{
    int size;
    
    size = get_stack_size(*stack_a);
    if (size <= 1)
        return;
    else if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_three(stack_a);
   // else if (size <= 5)
   //     sort_five(stack_a, stack_b);
   (void)stack_b;
  //  else
  //      sort_large(stack_a, stack_b);
}

int	main(int ac, char **av)
{	
	t_node *stack_a;
	t_node *stack_b;

	if (ac < 2)
		return (1);
	else if (argc == 2)
		av = ft_split(av[1], ' ');
	check_args(av);
	stack_a = init_stack_a(ac, av);
	stack_b = init_stack_b();
	
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	
	sb(&stack_b);
//	ra(&stack_a);
//	rb(&stack_b);
//	rr(&stack_a, &stack_b);
//	pa(&stack_a, &stack_b);
//	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}
