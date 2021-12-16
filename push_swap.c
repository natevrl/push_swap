/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/16 16:21:25 by nbenhado         ###   ########.fr       */
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

void	swap_b(char **tab, int max)
{
	char *tmp;
	
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
}


void	swap_a(char **tab, int max)
{
	char *tmp;
	
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
