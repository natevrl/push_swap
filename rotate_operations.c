/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:28:27 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/29 14:19:40 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a(char **tab, int max)
{
	char	*temp;
	int	vtop;

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
	int	vtop;

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
	int	vtop;

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
	int	vtop;

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

void	reverse_rotate_a(char **tab, int max)
{
	char	*temp;
	int	vtop;

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
	int	vtop;

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


void	reverse_rotate_a2(char **tab, int max)
{
	char	*temp;
	int	vtop;

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
	int	vtop;

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
