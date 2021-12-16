/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:05:38 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/16 20:36:29 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*void	split_print_stack(char **a, char **b, int number, char **args)
{
	int i;

	i = -1;
	if (number == 1)
	{
		a = ft_split(args[0], ' ');
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

			tab0[i] = args[i];
			printf("%s\n", tab0[i]);
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