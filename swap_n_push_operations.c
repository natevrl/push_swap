/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_n_push_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:08:10 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/18 22:11:25 by nbenhado         ###   ########.fr       */
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
		tmp = tab[first_empty_case(tab, max) + 1];
		tab[first_empty_case(tab, max) + 1] = tab[first_empty_case(tab, max) + 2];
		tab[first_empty_case(tab, max) + 2] = tmp;
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
		tmp = tab[first_empty_case(tab, max) + 1];
		tab[first_empty_case(tab, max) + 1] = tab[first_empty_case(tab, max) + 2];
		tab[first_empty_case(tab, max) + 2] = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_ss(char **a, char **b, int max)
{
	swap_a(a, max);
	swap_b(b, max);
}

// prend le premier element de a (le plus haut) et le met dans b (le plus bas possible), ne fait rient sur a est vide
void	push_b(char **a, char **b, int max)
{
	if (isempty(a, max))
		return ;
	if (isfull(a))
	{
		b[first_empty_case(b, max)] = a[0];
		a[0] = ft_strdup("\0");
	}
	else
	{
		b[first_empty_case(b, max)] = a[before_empty_case(a, max)];
		a[first_empty_case(a, max) + 1] = ft_strdup("\0");
	}
	ft_putstr_fd("pb\n", 1);
}

void	push_a(char **a, char **b, int max)
{
	if (isempty(b, max))
		return ;
	if (isfull(b))
	{
		a[first_empty_case(a, max)] = b[0];
		b[0] = ft_strdup("\0");
	}
	else
	{
		a[first_empty_case(a, max)] = b[before_empty_case(b, max)];
		b[first_empty_case(b, max) + 1] = ft_strdup("\0");
	}
	ft_putstr_fd("pa\n", 1);
}
