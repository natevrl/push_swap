/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:06:37 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 22:24:28 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	min_v(char **tab, int bot)
{
	int	minimal;
	int	vtop;

	vtop = top(tab, bot);
	minimal = ft_atoi(tab[vtop]);
	while (vtop <= bot - 2)
	{
		if (ft_atoi(tab[vtop]) < minimal)
			minimal = ft_atoi(tab[vtop]);
		vtop++;
	}
	return (minimal);
}

int	max_v(char **tab, int bot)
{
	int	minimal;
	int	vtop;

	vtop = top(tab, bot);
	minimal = ft_atoi(tab[vtop]);
	while (vtop <= bot - 2)
	{
		if (ft_atoi(tab[vtop]) > minimal)
			minimal = ft_atoi(tab[vtop]);
		vtop++;
	}
	return (minimal);
}

int	near_top(char **ctab, int maximal, int bot)
{
	int	mid_stack;
	int	vtop;

	vtop = top(ctab, bot);
	bot -= 2;
	mid_stack = ((bot - vtop) / 2);
	while (vtop <= (bot - mid_stack))
	{
		if (ft_atoi(ctab[vtop]) == maximal)
			return (1);
		vtop++;
	}
	return (-1);
}

static void	tab_swap(int *i, int *y)
{
	int	tampon;

	tampon = *i;
	*i = *y;
	*y = tampon;
}

int	*sort_tab(char **tab, int bot)
{
	int	i;
	int	y;
	int	*tab_de_int;

	tab_de_int = (int *)malloc(sizeof(int) * (bot - 1));
	if (!tab_de_int)
		return (NULL);
	i = -1;
	while (++i < (bot - 1))
		tab_de_int[i] = ft_atoi(tab[i]);
	i = -1;
	while (++i < (bot - 1))
	{
		y = i;
		while (++y < (bot - 1))
			if (tab_de_int[i] < tab_de_int[y])
				tab_swap(&tab_de_int[i], &tab_de_int[y]);
	}		
	return (tab_de_int);
}
