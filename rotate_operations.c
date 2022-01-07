/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:28:27 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 21:18:59 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	temp = tab[vtop];
	max -= 2;
	while (vtop < max)
	{
		tab[vtop] = tab[vtop + 1];
		vtop++;
	}
	tab[max] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	temp = tab[vtop];
	max -= 2;
	while (vtop < max)
	{
		tab[vtop] = tab[vtop + 1];
		vtop++;
	}
	tab[max] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_a2(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	temp = tab[vtop];
	max -= 2;
	while (vtop < max)
	{
		tab[vtop] = tab[vtop + 1];
		vtop++;
	}
	tab[max] = temp;
}

void	rotate_b2(char **tab, int max)
{
	char	*temp;
	int		vtop;

	if (isempty(tab, max))
		return ;
	vtop = top(tab, max);
	temp = tab[vtop];
	max -= 2;
	while (vtop < max)
	{
		tab[vtop] = tab[vtop + 1];
		vtop++;
	}
	tab[max] = temp;
}

void	rotate_rr(char **a, char **b, int max)
{
	rotate_a2(a, max);
	rotate_b2(b, max);
	ft_putstr_fd("rr\n", 1);
}
