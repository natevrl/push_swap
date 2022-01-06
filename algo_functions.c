/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:58:42 by v3r               #+#    #+#             */
/*   Updated: 2022/01/06 22:18:39 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_quarter(char **a, char **b, int bot, char **ptr_zero)
{
	int			i;
	int			parts;
	int			*sort;
	static int	quarter = 0;

	parts = 4;
	if (bot > 200)
		parts = 8;
	sort = sort_tab(a, bot);
	i = 0;
	while (i <= (bot - 2))
	{
		if (is_in_parts(sort, bot, ft_atoi(a[top(a, bot)]), quarter))
			push_b(a, b, bot, ptr_zero);
		else
		{
			if (!isempty(b, bot) && ft_atoi(b[top(b, bot)]) != max_v(b, bot))
				rotate_rr(a, b, bot);
			else
				rotate_a(a, bot);
		}
		i++;
	}
	quarter += ((bot - 1) / parts);
	free(sort);
}

void	reverse_push_quarter(char **a, char **b, int bot, char **ptr_zero)
{
	while (ft_atoi(a[bot - 2]) != max_v(a, bot))
	{
		reverse_rotate_a(a, bot);
		push_b(a, b, bot, ptr_zero);
	}
}

void	sort_quarter(char **a, char **b, int bot, char **ptr_zero)
{
	while (!isempty(b, bot))
	{
		if (ft_atoi(b[top(b, bot)]) == max_v(b, bot))
		{
			push_a(a, b, bot, ptr_zero);
		}
		else if (near_top(b, max_v(b, bot), bot) >= 0)
			rotate_b(b, bot);
		else
			reverse_rotate_b(b, bot);
	}
}
