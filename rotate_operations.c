/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:28:27 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/16 17:03:19 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a(char **tab, int max)
{
	char *temp;
	int top;

	if (isempty(tab, max))
		return ;
	top = before_empty_case(tab, max);
	temp = tab[top];
	max -= 2;
	while (top < max)
	{
		tab[top] = tab[top + 1];
		top++;
	}
	tab[max] = temp;
}

void	rotate_b(char **tab, int max)
{
	char *temp;
	int top;

	if (isempty(tab, max))
		return ;
	top = before_empty_case(tab, max);
	temp = tab[top];
	max -= 2;
	while (top < max)
	{
		tab[top] = tab[top + 1];
		top++;
	}
	tab[max] = temp;
}

void	rotate_rr(char **a, char **b, int max)
{
	rotate_a(a, max);
	rotate_b(b, max);
}

void	reverse_rotate_a(char **tab, int max)
{
	char *temp;
	int top;

	if (isempty(tab, max))
		return ;
	top = before_empty_case(tab, max);
	max -= 2;
	temp = tab[max];
	while (top < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[top] = temp;
}

void	reverse_rotate_b(char **tab, int max)
{
	char *temp;
	int top;

	if (isempty(tab, max))
		return ;
	top = before_empty_case(tab, max);
	max -= 2;
	temp = tab[max];
	while (top < max)
	{
		tab[max] = tab[max - 1];
		max--;
	}
	tab[top] = temp;
}

void	reverse_rotate_rr(char **a, char **b, int max)
{
	reverse_rotate_a(a, max);
	reverse_rotate_b(b, max);
}
