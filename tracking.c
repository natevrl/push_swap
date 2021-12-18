/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:06:37 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/18 18:51:12 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
// renvoie l'emplacement du premier chiffre en dessous d'une case vide
int before_empty_case(char **tab, int down)
{
	// je decremente de 2 : 1 pour lindex, 1 car argc compte le a.out
	down -= 2;
	while (down > 0)
	{
		if (ft_strlen(tab[down - 1]) == 0)
			return (down);
		down--;
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

int minimal_value(char **tab, int down)
{
    int minimal;
    int top;

    top = before_empty_case(tab, down);
    minimal = ft_atoi(tab[top]);
    while (top <= down - 2)
    {
        if (ft_atoi(tab[top]) < minimal)
            minimal = ft_atoi(tab[top]);
        top++;
    }   
    return (minimal);
}

// moitie de la stack = down - top / 2
int near_down(char **tab, int minimal, int down)
{
	int mid_stack;
	int top = before_empty_case(tab, down);
	down -= 2;
	mid_stack = (down - top) / 2;
	while (mid_stack <= down)
	{
		if(ft_atoi(tab[mid_stack]) == minimal)
			return (1);
		mid_stack++;
	}
	return (0);	
}