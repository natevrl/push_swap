/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:07:37 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 23:35:25 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	three_numbers(char **a, int bot)
{
	while (!is_sorted(a, bot))
	{
		if (ft_atoi(a[top(a, bot)]) == min_v(a, bot)
			|| ft_atoi(a[bot - 2]) == max_v(a, bot))
		{
			if (ft_atoi(a[bot - 2]) == max_v(a, bot)
				&& ft_atoi(a[top(a, bot)]) == min_v(a, bot))
				return ;
			else if (ft_atoi(a[top(a, bot)]) == min_v(a, bot))
			{
				reverse_rotate_a(a, bot);
				swap_a(a, bot);
				return ;
			}
			else if (ft_atoi(a[bot - 2]) == max_v(a, bot))
			{
				swap_a(a, bot);
				return ;
			}
		}
		else
			rotate_a(a, bot);
	}
}

static void	five_numbers(char **a, char **b, int bot, char **ptr_zero)
{
	int	y;

	y = 0;
	while (y <= 1)
	{
		if (ft_atoi(a[top(a, bot)]) == min_v(a, bot))
		{
			push_b(a, b, bot, ptr_zero);
			y++;
		}
		else if (near_top(a, min_v(a, bot), bot) >= 0)
			rotate_a(a, bot);
		else
			reverse_rotate_a(a, bot);
	}
	three_numbers(a, bot);
	push_a(a, b, bot, ptr_zero);
	push_a(a, b, bot, ptr_zero);
}

static void	main_algo(char **a, char **b, int bot, char **ptr_zero)
{
	int	y;
	int	parts;

	if (bot < 200)
		parts = 4;
	else
		parts = 8;
	y = 0;
	while (y < parts)
	{
		if (y < parts - 1)
			push_quarter(a, b, bot, ptr_zero);
		else
			reverse_push_quarter(a, b, bot, ptr_zero);
		sort_quarter(a, b, bot, ptr_zero);
		y++;
	}
}

static int	free_and_return(char *ptr_zero, char **b, char **a, int bot)
{
	int	i;

	i = 0;
	free(ptr_zero);
	while (i < bot)
	{
		free(a[i]);
		i++;
	}
	free(a);
	free(b);
	return (0);
}

int	main(int ac, char **av)
{
	char	**a;
	char	**b;
	char	*ptr_zero;

	ptr_zero = malloc(sizeof(char));
	ptr_zero[0] = '\0';
	a = init_stack_a(av, &ac);
	b = init_stack_b(ac, &ptr_zero);
	if (!swap_checker(a, ac) || is_sorted(a, ac))
	{
		if (!swap_checker(a, ac))
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ac < 5)
		three_numbers(a, ac);
	else if (ac == 6)
		five_numbers(a, b, ac, &ptr_zero);
	else
		main_algo(a, b, ac, &ptr_zero);
	return (free_and_return(ptr_zero, b, a, ac));
}
