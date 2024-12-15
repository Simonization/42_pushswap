/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:27:03 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 17:52:22 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_printlst(t_node *node)
{
	while(node)
	{
		printf("value: %d\n", node->value);
		node = node->next;
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_large(stack_a, stack_b);
}

char	**parse_arguments(int ac, char **av)
{
	char	**args;
	char	*str;
	char	*temp;
	
	if (ac == 2)
		return (ft_split(av[1], ' '));
	str = ft_strjoin(av[1], " ");
	for (int i = 2; i < ac; i++)
	{
		temp = str;
		str = ft_strjoin(temp, av[i]);
		free(temp);
		temp = str;
		str = ft_strjoin(temp, " ");
		free(temp);
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	// int args_count;

	if (ac < 2)
  	{
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
	args = parse_arguments(ac, av);
	if (!args || !args[0])
	{
		ft_putstr_fd("Error\n", 2);
		if (args)
			free(args);
		return (1);
	}
	if (!validate_args(args))
	{
		free_args(args);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// args_count = 0;
    // while (args[args_count])
    //     args_count++;
    init_stack_a(&stack_a,/* args_count + 1,*/ args); 
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b);
	free(args);
	free_stack(&stack_a);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// 	if (ac < 2)
// 		return (1);
// 	else if (ac == 2)
// 	{
// 		av = ft_split(av[1], ' ');
// 		if (!av || !av[0] || syntax_errors(av[0]))
//         {
//             ft_putstr_fd("Error\n", 2);
// 			if (av)
//                 free(av);
//             return (1);
//         }
// 		ac = split_av_size(av);
// 	}
// 	check_args(av);
// 	check_args_2(av);
// 	check_args_3(av);
// 	/* stack_a = */init_stack_a(&stack_a, ac, av);
// 	stack_b = NULL;
// 	//print_stacks(stack_a, stack_b); /*     debug   */
// 	//ft_printlst(stack_a);
// 	stack_b = init_stack_b();
// 	//print_stacks(stack_a, stack_b); /*     debug   */
// 	sort_stack(&stack_a, &stack_b);
// 	//print_stack(stack_a, stack_b);
// 	free_stack(&stack_a);
// 	return (0);
// }
