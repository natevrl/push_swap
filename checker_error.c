/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:33:12 by v3r               #+#    #+#             */
/*   Updated: 2022/01/29 19:29:16 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(char **a, int bot)
{
	int	i;

	i = 0;
	while (i < bot - 2)
	{
		if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static long long	atl(char *nptr)
{
	int			i;
	int			negatif;
	long long	result;

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

int	swap_checker(char **tab, int bot)
{
	int	vtop;
	int	i;

	vtop = 0;
	bot -= 2;
	while (vtop <= bot)
	{
		if (atl(tab[vtop]) > 2147483647 || atl(tab[vtop]) < -2147483648 || ft_strlen(tab[vtop]) > 12)
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
		i = vtop;
		while (++i <= bot)
			if (ft_atoi(tab[vtop]) == ft_atoi(tab[i]))
				return (0);
		vtop++;
	}
	return (1);
}
