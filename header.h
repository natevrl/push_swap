/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:13 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 21:20:51 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include "libft/libft.h"

// fonctions d'initialisation et d'affichage;
char	**init_stack_a(char **argv, int *ac);
char	**init_stack_b(int bot, char **ptr_zero);
void	split_print_stack(char **a, char **b, int number, char **args);
void	print_stack(char **a, char **b, int number);
int     swap_checker(char **tab, int bot);

// Tracking : fonctions de tcheck et de recuperation d'index;
int	isfull(char **tab);
int	isempty(char **tab, int max);
int	top(char **tab, int max);
int	first_empty(char **tab, int max);
int	min_v(char **tab, int bot);
int	max_v(char **tab, int bot);
int	near_top(char **ctab, int maximal, int bot);
int	is_in_parts(int *itab, int bot, int number, int quarter);
int	*sort_tab(char **tab, int bot);
int	is_sorted(char **a, int bot);

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

// fonctions qui consitue l'algo
void	sort_quarter(char **a, char **b, int bot, char **ptr_zero);
void	reverse_push_quarter(char **a, char **b, int bot, char **ptr_zero);
void	push_quarter(char **a, char **b, int bot, char **ptr_zero);

#endif
