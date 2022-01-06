/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:13 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 17:59:47 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

// fonctions d'initialisation et d'affichage;
char	**init_stack_a(char **argv, int *ac);
char	**init_stack_b(int down, char **ptr_zero);
void	split_print_stack(char **a, char **b, int number, char **args);
void	print_stack(char **a, char **b, int number);
int	swap_checker(char **tab, int down);

// Tracking : fonctions de tcheck et de recuperation d'index;
int	isfull(char **tab);
int	isempty(char **tab, int max);
int	top(char **tab, int max);
int	first_empty_case(char **tab, int max);
int	minimal_value(char **tab, int down);
int	maximal_value(char **tab, int down);
int near_down(char **tab, int minimal, int down);
int near_top(char **ctab, int maximal, int down);
int near_top_tabs(char **ctab, int *itab, int down);
int near_down_tabs(char **ctab, int *itab, int down);

int	there_is_midtier(int *itab, char **ctab, int down, int vtop);
int	is_in_midtier(int *itab, int down, int number);
int	there_is_parts(int *itab, char **ctab, int down, int vtop, int quarter, int parts);
int	is_in_parts(int *itab, int down, int number, int quarter, int parts);
int	*sort_tab(char **tab, int down);
int is_sorted(char **a, int down);



// fonctions de swap;
void	swap_a(char **tab, int max);
void	swap_b(char **tab, int max);
void	swap_ss(char **a, char **b, int max);

// fonctions de push;
void	push_a(char **a, char **b, int max, char **ptr_zero);
void	push_b(char **a, char **b, int max, char **ptr_zero);

// fonctions de rotate;
void	rotate_a(char **tab, int max);
void	rotate_b(char **tab, int max);
void	rotate_a2(char **tab, int max);
void	rotate_b2(char **tab, int max);
void	rotate_rr(char **a, char **b, int max);
void	reverse_rotate_a(char **tab, int max);
void	reverse_rotate_b(char **tab, int max);
void	reverse_rotate_a2(char **tab, int max);
void	reverse_rotate_b2(char **tab, int max);
void	reverse_rotate_rr(char **a, char **b, int max);

//main
void	big_stack_sorting(char **a, char **b, int down);
void	three_numbers(char **a, int down);
void	main_algo(char **a, char **b, int down, int parts, char **ptr_zero);
void	sort_quarter(char **a, char **b, int down, char **ptr_zero);
void	reverse_push_quarter(char **a, char **b, int down, char **ptr_zero);
void	push_quarter(char **a, char **b, int down, int parts, char **ptr_zero);

#endif
