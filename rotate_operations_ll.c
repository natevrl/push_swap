/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations_ll.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:28:55 by v3r               #+#    #+#             */
/*   Updated: 2022/01/07 21:19:30 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reverse_rotate_a2(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	max -= 2;
	temp = tab[max];
	while (vtop < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[vtop] = temp;
}

void	reverse_rotate_b2(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	max -= 2;
	temp = tab[max];
	while (vtop < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[vtop] = temp;
}

void	reverse_rotate_rr(char **a, char **b, int max)
{
	reverse_rotate_a2(a, max);
	reverse_rotate_b2(b, max);
	ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_a(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	max -= 2;
	temp = tab[max];
	while (vtop < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[vtop] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	max -= 2;
	temp = tab[max];
	while (vtop < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[vtop] = temp;
	ft_putstr_fd("rrb\n", 1);
}
