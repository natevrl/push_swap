/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_n_push_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:08:10 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 21:21:05 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap_b(char **tab, int max)
{
	char	*tmp;

	if (isempty(tab, max))
		return ;
	if (isfull(tab))
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
	else
	{
		tmp = tab[first_empty(tab, max) + 1];
		tab[first_empty(tab, max) + 1] = tab[first_empty(tab, max) + 2];
		tab[first_empty(tab, max) + 2] = tmp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_a(char **tab, int max)
{
	char	*tmp;

	if (isempty(tab, max))
		return ;
	if (isfull(tab))
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
	else
	{
		tmp = tab[first_empty(tab, max) + 1];
		tab[first_empty(tab, max) + 1] = tab[first_empty(tab, max) + 2];
		tab[first_empty(tab, max) + 2] = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_ss(char **a, char **b, int max)
{
	swap_a(a, max);
	swap_b(b, max);
}

void	push_b(char **a, char **b, int max, char **ptr_zero)
{
	if (isempty(a, max))
		return ;
	if (isfull(a))
	{
		b[first_empty(b, max)] = a[0];
		a[0] = *ptr_zero;
	}
	else
	{
		b[first_empty(b, max)] = a[top(a, max)];
		a[first_empty(a, max) + 1] = *ptr_zero;
	}
	ft_putstr_fd("pb\n", 1);
}

void	push_a(char **a, char **b, int max, char **ptr_zero)
{
	if (isempty(b, max))
		return ;
	if (isfull(b))
	{
		a[first_empty(a, max)] = b[0];
		b[0] = *ptr_zero;
	}
	else
	{
		a[first_empty(a, max)] = b[top(b, max)];
		b[first_empty(b, max) + 1] = *ptr_zero;
	}
	ft_putstr_fd("pa\n", 1);
}
