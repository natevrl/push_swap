/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:14:03 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/19 19:25:16 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**init_stack_b(int bot, char **ptr_zero)
{
	char	**b;
	int		i;

	b = malloc(sizeof(char *) * bot);
	if (b == NULL)
		return (NULL);
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
	if (tab_de_str == NULL)
		return (NULL);
	y = 0;
	i = 0;
	while (++y < *ac)
	{
		tab_de_str[i] = ft_strdup(argv[y]);
		i++;
	}
	tab_de_str[i] = ft_strdup("\0");
	return (tab_de_str);
}
