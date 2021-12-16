#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

// fonctions d'initialisation et d'affichage;
char **init_stack_a(char **argv, int numb);
char **init_stack_b(int numb);
void	split_print_stack(char **a, char **b, int number, char **args);
void	print_stack(char **a, char **b, int number);

// fonctions de tcheck et de recuperation d'index;
int isfull(char **tab);
int isempty(char **tab, int max);
int before_empty_case(char **tab, int max);
int first_empty_case(char **tab, int max);

// fonctions de swap;
void	swap_a(char **tab, int max);
void	swap_b(char **tab, int max);

// fonctions de push;
void	push_a(char **a, char **b, int max);
void	push_b(char **a, char **b, int max);
void	swap_ss(char **a, char **b, int max);

// fonctions de rotate;
void	rotate_a(char **tab, int max);
void	rotate_b(char **tab, int max);
void	rotate_rr(char **a, char **b, int max);
void	reverse_rotate_a(char **tab, int max);
void	reverse_rotate_b(char **tab, int max);
void	reverse_rotate_rr(char **a, char **b, int max);

#endif