/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:14:03 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/05 15:52:34 by nbenhado         ###   ########.fr       */
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
	int	i;

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

char	**init_stack_b(int numb)
{
	char	**tab_de_str;
	int		i;

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

char	**init_stack_a(char **argv, int *ac)
{
	char	**tab_de_str;
	int		i;
	int		y;

	i = 0;
	if (*ac == 2)
	{
		tab_de_str = ft_split(argv[1], ' ');
		while (tab_de_str[i])
			i++;
		*ac = i + 1;
		return (tab_de_str);
	}
	tab_de_str = malloc(sizeof(char **) * *ac);
	y = 1;
	i = 0;
	while (y < *ac)
	{
		tab_de_str[i] = ft_strdup(argv[y]);
		i++;
		y++;
	}
	tab_de_str[i] = ft_strdup("\0");
	return (tab_de_str);
}

long long       atoilong(char *nptr)
{
        int             i;
        int             negatif;
        int             result;

        i = 0;
        result = 0;
        negatif = 1;
        while ((nptr[i] >= 9 && nptr[i] <= 13) | (nptr[i] == ' '))
                i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
                if (nptr[i] == '-')
                        negatif = -1;
                i++;
        }
        i -= 1;
        while (nptr[++i] >= '0' && nptr[i] <= '9')
                result = result * 10 + nptr[i] - '0';
        result *= negatif;
        return (result);
}


// Permet de check : 
// 1 = aucun nombre depasse le max/min INT 
// 2 = Tout les nombre sont bien des digit (- pour les negatif inclus)
// 3 = Qu'il m'y a aucun doublon
int	swap_checker(char **tab, int down)
{
	int	vtop;
	int	i;

	vtop = 0;
	down -= 2;
	while (vtop <= down)
	{
		if (atoilong(tab[vtop]) > 2147483647 || atoilong(tab[vtop]) < -2147483648)
			return (0);
		i = 0;
		if (tab[vtop][0] == '-')
			i++;
		while (tab[vtop][i])
		{
			if (tab[vtop][i] < '0' || tab[vtop][i] > '9')
				return (0);
			i++;
		}
		i = vtop + 1;
		while (i <= down)
		{
			if (ft_atoi(tab[vtop]) == ft_atoi(tab[i]))
				return (0);
			i++;
		}
		vtop++;
	}
	return (1);
}
