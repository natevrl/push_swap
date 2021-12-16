/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/15 21:50:34 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

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
		tab_de_str[i] = ft_strdup("\0");
		i++;
	}
	tab_de_str[i] = ft_strdup("\0");
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
		tab_de_str[i] = ft_strdup(argv[y]);
		i++;
		y++;
	}
	tab_de_str[i] = ft_strdup("\0");
	return (tab_de_str);
}

//renvoi l'emplacement de la premiere case vide trouver (ou le premier si full)
int first_empty_case(char **tab, int max)
{
	// je decremente de 2 : 1 pour lindex, 1 car argc compte le a.out
	max -= 2;
	while (max > 0)
	{
		if (ft_strlen(tab[max]) == 0)
			return (max);
		max--;
	}
	return (0);
}

int isempty(char **tab, int max)
{
	if (ft_strlen(tab[max - 2]) == 0)
		return (1);
	return (0);
}

int isfull(char **tab)
{
	if (ft_strlen(tab[0]) != 0)
		return (1);
	return (0);
}

void	swap_b(char **tab)
{
	char *tmp;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	swap_a(char **tab, int max)
{
	char *tmp;
	
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
		b[first_empty_case(b, max)] = a[first_empty_case(a, max) + 1];
		a[first_empty_case(a, max) + 1] = ft_strdup("\0");
	}
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
		a[first_empty_case(a, max)] = b[first_empty_case(b, max) + 1];
		b[first_empty_case(b, max) + 1] = ft_strdup("\0");
	}
}

int main(int ac, char **av)
{
	char **a;
	char **b;

	printf("valeur de AC : %d\n", ac);
	a = init_stack_a(av, ac);
	b = init_stack_b(ac);
	print_stack(a, b, ac);
	push_b(a, b, ac);
	push_b(a, b, ac);
	print_stack(a, b, ac);
	swap_a(b, ac);
	print_stack(a, b, ac);
	return (0);
}
