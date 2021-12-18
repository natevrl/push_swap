/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:13 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/18 18:09:06 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

// fonctions d'initialisation et d'affichage;
char **init_stack_a(char **argv, int *ac);
char **init_stack_b(int numb);
void	split_print_stack(char **a, char **b, int number, char **args);
void	print_stack(char **a, char **b, int number);
int	swap_checker(char **tab, int down);

// fonctions de tcheck et de recuperation d'index;
int isfull(char **tab);
int isempty(char **tab, int max);
int before_empty_case(char **tab, int max);
int first_empty_case(char **tab, int max);
int minimal_value(char **tab, int down);
int near_down(char **tab, int minimal_value, int down);

// fonctions de swap;
void	swap_a(char **tab, int max);
void	swap_b(char **tab, int max);
void	swap_ss(char **a, char **b, int max);

// fonctions de push;
void	push_a(char **a, char **b, int max);
void	push_b(char **a, char **b, int max);

// fonctions de rotate;
void	rotate_a(char **tab, int max);
void	rotate_b(char **tab, int max);
void	rotate_rr(char **a, char **b, int max);
void	reverse_rotate_a(char **tab, int max);
void	reverse_rotate_b(char **tab, int max);
void	reverse_rotate_rr(char **a, char **b, int max);

//main
void	main_algo(char **a, char **b, int down);

#endif