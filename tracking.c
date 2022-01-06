/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:06:37 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 14:47:12 by v3r              ###   ########.fr       */
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
int	top(char **tab, int down)
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
	int	vtop;

	vtop = top(tab, down);
	minimal = ft_atoi(tab[vtop]);
	while (vtop <= down - 2)
	{
		if (ft_atoi(tab[vtop]) < minimal)
			minimal = ft_atoi(tab[vtop]);
		vtop++;
	}   
	return (minimal);
}

int	maximal_value(char **tab, int down)
{
	int	minimal;
	int	vtop;

	vtop = top(tab, down);
	minimal = ft_atoi(tab[vtop]);
	while (vtop <= down - 2)
	{
		if (ft_atoi(tab[vtop]) > minimal)
			minimal = ft_atoi(tab[vtop]);
		vtop++;
	}   
	return (minimal);
}

//un tier de la stack  = own - vtop) / 3) * 2
// mid_stack + vtop = le haut de la stack + lajout des 2/3 = donc le bas de la stack
int near_down(char **tab, int maximal, int down)
{
	int mid_stack;
	int vtop = top(tab, down);
	down -= 2;
	mid_stack = ((down - vtop) / 2);
	// printf("midstack = %d\n", mid_stack);
	// printf("down = %d\n", down - vtop);
	// printf("vtop = %d\n", vtop);
	while (mid_stack + vtop <= down)
	{
		if(ft_atoi(tab[mid_stack + vtop]) == maximal)
			return (1);
		mid_stack++;
	}
	return (0);	
}

int near_top(char **ctab, int maximal, int down)
{
	int mid_stack;
	int vtop = top(ctab, down);
	down -= 2;
	mid_stack = ( (down - vtop) / 2 );
	while (vtop <= (down - mid_stack))
	{
		if(ft_atoi(ctab[vtop]) == maximal)
			return (1);
		vtop++;
	}
	return (-1);	
}

int near_vtop_tabs(char **ctab, int *itab, int down)
{
	int mid_stack;
	int vtop = top(ctab, down);
	int i;
	int compteur = 1;
	down -= 2;
	mid_stack = ( (down - vtop) / 2);
	while (vtop <= down - mid_stack)
	{
		i = 0;
		while (i < down / 2 )
		{
			if(ft_atoi(ctab[vtop]) == itab[i])
				return (compteur);
			i++;
		}
		vtop++;
		compteur++;
	}
	return (-1);	
}

int near_down_tabs(char **ctab, int *itab, int down)
{
	int mid_stack;
	int vtop = top(ctab, down);
	int i;
	int compteur = 1;
	down -= 2;
	mid_stack = ( (down - vtop) / 2);
	while (down >= vtop + mid_stack)
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
	int tampon;
	int	*tab_de_int;

	taille_actuel = (down - 1);
	tab_de_int = (int	*)malloc(sizeof(int) * taille_actuel);
	if (!tab_de_int)
		return (NULL);
	i = 0;
	while (i <= taille_actuel)
	{
		tab_de_int[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	while (i <= taille_actuel)
	{
		y = i + 1;
		while (y <= taille_actuel)
		{
			if (tab_de_int[i] < tab_de_int[y])
			{
				tampon = tab_de_int[i];
				tab_de_int[i] = tab_de_int[y];
				tab_de_int[y] = tampon;
			}
			y++;
		}
		i++;
	}		
	return (tab_de_int);
}

int is_sorted(char **a, int down)
{
	int i;

	i = 0;
	while (i < down - 2)
	{
		if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
			return (0);
		i++;
	}
	return (1);
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

int	there_is_midtier(int *itab, char **ctab, int down, int vtop)
{

	int	y;

	while (vtop <= down - 2)
	{
		y = 0;
		while (y < (down - 2) / 2)
		{
			if(ft_atoi(ctab[vtop]) == itab[y])
				return (1);
			y++;
		}
		vtop++;
	}
	return (0);
}

int	is_in_parts(int *itab, int down, int number, int quarter, int parts)
{
	int	i;

	i = 0;
	while (i <= ( (down - 2) / parts ) )
	{
		if(itab[quarter + i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	there_is_parts(int *itab, char **ctab, int down, int vtop, int quarter, int parts)
{
	int i;
	down -= 2;
	while (vtop <= down)
	{
		i = 0;
		while (i <= down / parts)
		{
			if(ft_atoi(ctab[vtop]) == itab[quarter + i])
				return (1);
			i++;
		}
		vtop++;
	}
	return (0);
}
