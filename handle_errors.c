/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:55:53 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/14 17:40:01 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char **args)
{
	write(2, "Error\n", 6);
	if (args)
		free_args(args);
	exit(1);
}

long	ft_atol(char *argv)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (argv[i] == '\f' || argv[i] == '\n' || argv[i] == '\r'
		|| argv[i] == '\t' || argv[i] == '\v' || argv[i] == ' ')
		i++;
	if (argv[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (argv[i] == '+')
		i++;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		result = result * 10 + (argv[i] - '0');
		i++;
	}
	return (result * sign);
}

int	error_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	error_syntax(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& !ft_isdigit(argv[i][j + 1]))
			return (1);
		else if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& (argv[i][j + 1] != '\0' || argv[i][j + 1] != ' '))
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] == 32)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
