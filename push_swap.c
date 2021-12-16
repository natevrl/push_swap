/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/16 17:08:52 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int before_empty_case(char **tab, int max)
{
	// je decremente de 2 : 1 pour lindex, 1 car argc compte le a.out
	max -= 2;
	while (max > 0)
	{
		if (ft_strlen(tab[max - 1]) == 0)
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



int main(int ac, char **av)
{
	char **a;
	char **b;

	printf("valeur de AC : %d\n", ac);
	a = init_stack_a(av, ac);
	b = init_stack_b(ac);
	printf("%d || %d\n", before_empty_case(a, ac), first_empty_case(a, ac));
	print_stack(a, b, ac);
	reverse_rotate_a(a, ac);
	print_stack(a, b, ac);
	reverse_rotate_a(a, ac);
	print_stack(a, b, ac);
	rotate_a(a, ac);
	rotate_a(a, ac);
	print_stack(a, b, ac);
	return (0);
}
