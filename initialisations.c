/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:14:03 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 22:28:15 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	print_stack(char **a, char **b, int number)
// {
// 	int	i;

// 	i = 0;
// 	while (i < number - 1)
// 	{
// 		printf("%s	|    %s\n", a[i], b[i]);
// 		i++;
// 	}
// 	printf(" -		-\n");
// 	printf(" a		b\n");
// 	printf("-----------------\n");
// }

char	**init_stack_b(int bot, char **ptr_zero)
{
	char	**b;
	int		i;

	b = malloc(sizeof(char *) * bot);
	i = 0;
	while (i < bot)
	{
		b[i] = *ptr_zero;
		i++;
	}
	return (b);
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
