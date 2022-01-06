/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:31:58 by v3r               #+#    #+#             */
/*   Updated: 2022/01/06 22:24:38 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//renvoi l'emplacement de la premiere case vide trouver (ou le premier si full)
int	first_empty_case(char **tab, int max)
{
	max -= 2;
	while (max > 0)
	{
		if (ft_strlen(tab[max]) == 0)
			return (max);
		max--;
	}
	return (0);
}

// renvoie l'emplacement du premier chiffre en dessous d'une case vide
int	top(char **tab, int bot)
{
	bot -= 2;
	while (bot > 0)
	{
		if (ft_strlen(tab[bot - 1]) == 0)
			return (bot);
		bot--;
	}
	return (0);
}

int	isempty(char **tab, int max)
{
	if (ft_strlen(tab[max - 2]) == 0)
		return (1);
	return (0);
}

int	isfull(char **tab)
{
	if (ft_strlen(tab[0]) != 0)
		return (1);
	return (0);
}

int	is_in_parts(int *itab, int bot, int number, int quarter)
{
	int	i;
	int	parts;

	if (bot < 200)
		parts = 4;
	else
		parts = 8;
	i = 0;
	while (i <= ((bot - 2) / parts))
	{
		if (itab[quarter + i] == number)
			return (1);
		i++;
	}
	return (0);
}
