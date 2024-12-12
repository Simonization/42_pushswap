/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:26:40 by slangero          #+#    #+#             */
/*   Updated: 2024/11/11 19:05:22 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	split_av_size(char **av)
{
	size_t	i;

	i = 0;
	while (*av)
	{
		i++;
		av++;
	}
	return (i);
}

long int	ft_atol(const char *str)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char **argv)
{
	int			i;
	int			j;
	long int	num1;
	long int	num2;

	i = 1;
	while (argv[i])
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_args(char **argv)
{
	int			i;
	long int	num;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			exit_error(NULL, NULL, &argv[i]);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error(NULL, NULL, &argv[i]);
		i++;
	}
	if (has_duplicates(argv))
		exit_error(NULL, NULL, &argv[i]);
}
