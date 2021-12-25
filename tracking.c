/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:06:37 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/25 12:25:27 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//renvoi l'emplacement de la premiere case vide trouver (ou le premier si full)
int	first_empty_case(char **tab, int max)
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
int	before_empty_case(char **tab, int down)
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

int	minimal_value(char **tab, int down)
{
	int	minimal;
	int	top;

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

int	maximal_value(char **tab, int down)
{
	int	minimal;
	int	top;

	top = before_empty_case(tab, down);
	minimal = ft_atoi(tab[top]);
	while (top <= down - 2)
	{
		if (ft_atoi(tab[top]) > minimal)
			minimal = ft_atoi(tab[top]);
		top++;
	}   
	return (minimal);
}


//un tier de la stack  = own - top) / 3) * 2
// mid_stack + top = le haut de la stack + lajout des 2/3 = donc le bas de la stack
int near_down(char **tab, int maximal, int down)
{
	int mid_stack;
	int top = before_empty_case(tab, down);
	down -= 2;
	mid_stack = ((down - top) / 2);
	// printf("midstack = %d\n", mid_stack);
	// printf("down = %d\n", down - top);
	// printf("top = %d\n", top);
	while (mid_stack + top <= down)
	{
		if(ft_atoi(tab[mid_stack + top]) == maximal)
			return (1);
		mid_stack++;
	}
	return (0);	
}

int near_top_tabs(char **ctab, int *itab, int down)
{
	int mid_stack;
	int top = before_empty_case(ctab, down);
	int i;
	int compteur = 1;
	down -= 2;
	mid_stack = ( (down - top) / 2);
	while (top <= down - mid_stack)
	{
		i = 0;
		while (i < down / 2 )
		{
			if(ft_atoi(ctab[top]) == itab[i])
				return (compteur);
			i++;
		}
		top++;
		compteur++;
	}
	return (-1);	
}

int near_down_tabs(char **ctab, int *itab, int down)
{
	int mid_stack;
	int top = before_empty_case(ctab, down);
	int i;
	int compteur = 1;
	down -= 2;
	mid_stack = ( (down - top) / 2);
	while (down >= top + mid_stack)
	{
		i = 0;
		while (i < down / 2 )
		{
			if(ft_atoi(ctab[down]) == itab[i])
				return (compteur);
			i++;
		}
		down--;
		compteur++;
	}
	return (-1);	
}


// static int comp (const void * elem1, const void * elem2) 
// {
//     int f = *((int*)elem1);
//     int s = *((int*)elem2);
//     if (f > s) return  1;
//     if (f < s) return -1;
//     return 0;
// }

int	*sort_tab(char **tab, int down)
{
	int	taille_actuel;
	int	i;
	int y;
	int t;
	int	*tmp;

	taille_actuel = (down - 2);
	tmp = (int	*)malloc(sizeof(int) * taille_actuel);
	i = 0;
	while (i <= taille_actuel)
	{
		tmp[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while (i <= taille_actuel)
	{
		y = i + 1;
		while (y <= taille_actuel)
		{
			if (tmp[i] > tmp[y])
			{
				t = tmp[i];
				tmp[i] = tmp[y];
				tmp[y] = t;
			}
			y++;
		}
		i++;
	}		
	return (tmp);
}

int	is_in_midtier(int *itab, int down, int number)
{
	int	i;

	i = 0;
	while (i < ( (down - 2) / 2 ) )
	{
		if(itab[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	there_is_midtier(int *itab, char **ctab, int down, int top)
{

	int	y;

	while (top <= down - 2)
	{
		y = 0;
		while (y < (down - 2) / 2)
		{
			if(ft_atoi(ctab[top]) == itab[y])
				return (1);
			y++;
		}
		top++;
	}
	return (0);
}

int	is_in_quarter(int *itab, int down, int number, int quarter)
{
	int	i;

	i = 0;
	while (i <= ( (down - 2) / 4 ) )
	{
		if(itab[quarter + i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	there_is_quarter(int *itab, char **ctab, int down, int top, int quarter)
{
	int i;
	down -= 2;
	while (top <= down)
	{
		i = 0;
		while (i <= down / 4)
		{
			if(ft_atoi(ctab[top]) == itab[quarter + i])
				return (1);
			i++;
		}
		top++;
	}
	return (0);
}
