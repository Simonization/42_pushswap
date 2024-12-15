/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:26:40 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 18:29:24 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int is_invalid_sign(char *str)
{
	if (!str || !*str)
		return (1);
	if ((*str == '+' || *str == '-') && *(str + 1) == '\0')
		return (1);
		
	return (0);
}

int	syntax_errors(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int is_within_limits(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int    has_duplicates(char **argv)
{
	int        i;
	int        j;
	long int    num1;
	long int    num2;

	i = 0;
	while (argv[i])
	{
		num1 = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num2 = ft_atol(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(char **argv)
{
	int	i;
	int	zero_count;

	i = 0;
	zero_count = 0;
	while (argv[i])
	{

		if (syntax_errors(argv[i]))
			return (0);
		if (!is_within_limits(argv[i]))
			return (0);
		if (ft_atol(argv[i]) == 0)
			zero_count++;
		if (zero_count > 1)
			return (0);
		if (is_invalid_sign(argv[i]))
			return (0);

		i++;
	}
	if (has_duplicates(argv))
		return (0);
	return (1);
}