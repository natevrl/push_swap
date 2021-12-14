/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/14 16:07:14 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define SIZE 5

#include <stdio.h>
void	print_tab(int *tab1, int *tab2)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		printf("%d  %d\n", tab1[i], tab2[i]);
		i++;
	}
	printf("-  -\n");
	printf("a  b\n");
	printf("\n--------\n");
}

void	swap_a(int *tab)
{
	int i;
	i = tab[0];
	tab[0] = tab[1];
	tab[1] = i;
}

void	swap_b(int *tab)
{
	int i;
	if (!tab)
		printf("vide");
	i = tab[0];
	tab[0] = tab[1];
	tab[1] = i;
}

void	swap_ss(int *tab1, int *tab2)
{
	int i;
	i = tab1[0];
	tab1[0] = tab1[1];
	tab1[1] = i;	
	i = tab2[0];
	tab2[0] = tab2[1];
	tab2[1] = i;

}

void	push_b(int *a, int *b)
{
	b[SIZE - 1] = a[0];		
}


int main()
{
	int tab1[SIZE] = {1, 3, 4, 2, 6};
	int tab2[SIZE] = {};
	print_tab(tab1, tab2);
	push_b(tab1, tab2);
	push_b(tab1, tab2);
	push_b(tab1, tab2);
	print_tab(tab1, tab2);
	return (0);
}
