/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:55:40 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/15 12:24:06 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **arguments)
{
	int	idx;

	idx = 0;
	while (arguments[idx])
		free(arguments[idx++]);
	free(arguments);
}

char	**parse_args(int argc, char **argv)
{
	char	**args;
	char	*merge;
	char	*tmp;
	char	*tmp2;
	int		idx;

	idx = 1;
	merge = NULL;
	while (idx < argc)
	{
		tmp = merge;
		if (merge == NULL)
			merge = ft_strdup(argv[idx]);
		else
		{
			merge = ft_strjoin(merge, " ");
			tmp2 = merge;
			merge = ft_strjoin(merge, argv[idx]);
			free(tmp2);
		}
		idx++;
		free(tmp);
	}
	args = ft_split(merge, ' ');
	return (free(merge), args);
}

int	is_argv_null(int argc, char **str)
{
	int	i;
	int	j;
	int	only_spaces;

	if (argc < 2)
		exit(1);
	if (!str[1])
		print_error(NULL);
	i = 1;
	while (str[i])
	{
		j = 0;
		only_spaces = 1;
		while (str[i][j])
		{
			if (str[i][j] != ' ')
				only_spaces = 0;
			j++;
		}
		if (only_spaces)
			print_error(NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	is_argv_null(argc, argv);
	args = parse_args(argc, argv);
	if (error_syntax(args) || error_int(args) || error_dup(args))
		print_error(args);
	fill_stack(&a, args);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	(free_args(args), ft_free_stack(&a));
	return (0);
}
