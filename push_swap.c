/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/15 15:43:26 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
# define SIZE 5

/*void	split_print_stack(char **a, char **b, int number, char **args)
{
	int i;

	i = 0;
	if (number == 2)
	{
		a = ft_split(args[1], ' ');
		while (a[i])
		{
			printf("%s		|		%s\n", a[i], b[i]);
			i++;
		}
	}
	else
	{
		while (i < number)
		{

			tab1[i] = args[i];
			printf("%s\n", tab1[i]);
			i++;
		}
	}
	printf("-  -\n");
	printf("a  b\n");
	printf("--------\n");
}*/


void	print_stack(char **a, char **b, int number)
{
	int i;

	i = 0;


	while (i < number - 1)
	{
		printf("%s	|    %s\n", a[i], b[i]);
		i++;
	}
	printf(" -		-\n");
	printf(" a		b\n");
	printf("-----------------\n");
}

char **init_stack_b(int numb)
{
	char	**tab_de_str;
	int 	i;
	
	i = 0;
	tab_de_str = malloc(sizeof(char **) * numb);
	while (i + 1 < numb)
	{
		tab_de_str[i] = "";
		i++;
	}
	tab_de_str[i] = 0;
	return (tab_de_str);
}

char **init_stack_a(char **argv, int numb)
{
	char **tab_de_str;
	int i = 0;
	int y = 1;

	tab_de_str = malloc(sizeof(char **) * numb);
	while (y < numb)
	{
		tab_de_str[i] = argv[y];
		i++;
		y++;
	}
	tab_de_str[i] = 0;
	return (tab_de_str);
}
//renvoi l'emplacement de la premiere case vide trouver (ou le premier si full)
int empty_or_max(char **tab, int max)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (max  > 0)
	{
		max--;	
		if (!tab[max])
			return (max - 1);
	}
	return (1);
}

void	swap_b(char **tab)
{
	char *tmp;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	swap_a(char **tab)
{
	char *tmp;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

// prend le premier element de a (le plus haut) et le met dans b (le plus bas possible), ne fait rient sur a est vide
void	push_b(char **a, char **b, int max)
{
	b[empty_or_max(b, max)] = a[empty_or_max(a, max)];
	a[empty_or_max(a, max)] = "";
}

int main(int ac, char **av)
{
	char **a;
	char **b;

	printf("valeur de AC : %d\n", ac);
	a = init_stack_a(av, ac);
	b = init_stack_b(ac);
	//printf("%s\n", tab1[1]);
	print_stack(a, b, ac);
	push_b(a, b, ac);
	print_stack(a, b, ac);
	printf("%d\n", empty_or_max(a, ac));

	return (0);
}
