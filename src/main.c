/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:27:03 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:25:41 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**parse_arguments(int ac, char **av)
{
	char	**args;
	char	*str;
	char	*temp;
	int		i;

	if (ac == 2)
		return (ft_split(av[1], ' '));
	str = ft_strjoin(av[1], " ");
	i = 2;
	while (i < ac)
	{
		temp = str;
		str = ft_strjoin(temp, av[i]);
		free(temp);
		temp = str;
		str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

int	init_and_validate(int ac, char **av, t_node **stack_a)
{
	char	**args;

	if (ac < 2)
		return (handle_input_error(NULL));
	args = parse_arguments(ac, av);
	if (!args || !args[0])
		return (handle_input_error(args));
	if (!validate_args(args))
	{
		free_args(args);
		return (handle_input_error(NULL));
	}
	init_stack_a(stack_a, args);
	free_args(args);
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (init_and_validate(ac, av, &stack_a))
		return (1);
	if (!stack_is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	free_stack(&stack_a);
	return (0);
}
