/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:07:37 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 18:31:04 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	three_numbers(char **a, int down)
{
	while (!is_sorted(a, down))
	{
		if (ft_atoi(a[top(a, down)]) == minimal_value(a, down)
			|| ft_atoi(a[down - 2]) == maximal_value(a, down))
		{
			if (ft_atoi(a[down - 2]) == maximal_value(a, down)
				&& ft_atoi(a[top(a, down)]) == minimal_value(a, down))
				return ;
			else if (ft_atoi(a[top(a, down)]) == minimal_value(a, down))
			{
				reverse_rotate_a(a, down);
				swap_a(a, down);
				return ;
			}
			else if (ft_atoi(a[down - 2]) == maximal_value(a, down))
			{
				swap_a(a, down);
				return ;
			}
		}
		else
			rotate_a(a, down);
	}
}

void	push_quarter(char **a, char **b, int down, int parts, char **ptr_zero)
{
	int	i;
	int	*sort;
	static int quarter = 0;

	sort = sort_tab(a, down);
	i = 0;
	while (i <= (down - 2))
	{
		if (is_in_parts(sort, down, ft_atoi(a[top(a, down)]), quarter, parts))
			push_b(a, b, down, ptr_zero);
		else
		{
			if (!isempty(b, down) && ft_atoi(b[top(b, down)]) != maximal_value(b, down))
				rotate_rr(a, b, down);
			else
				rotate_a(a, down);
		}
		i++;
	}
	quarter += ((down - 1) / parts);
	free(sort);
}


void	reverse_push_quarter(char **a, char **b, int down, char **ptr_zero)
{
	while (ft_atoi(a[down - 2]) != maximal_value(a, down))
	{
		reverse_rotate_a(a, down);
		push_b(a, b, down, ptr_zero);
	}
}

void	sort_quarter(char **a, char **b, int down, char **ptr_zero)
{
	while (!isempty(b, down))
	{
		if (ft_atoi(b[top(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down, ptr_zero);
		}
		else if (near_top(b, maximal_value(b, down), down) >= 0)
			rotate_b(b, down);
		else
			reverse_rotate_b(b, down);
	}
}

void	five_numbers(char **a, char **b, int down, char **ptr_zero)
{
	int y;

	y = 0;
	while (y <= 1)
	{
		if (ft_atoi(a[top(a, down)]) == minimal_value(a, down))
		{
			push_b(a, b, down, ptr_zero);
			y++;		
		}
		else if (near_top(a, minimal_value(a, down), down) >= 0)
			rotate_a(a, down);
		else
			reverse_rotate_a(a, down);
	}
	three_numbers(a, down);
	push_a(a, b, down, ptr_zero);
	push_a(a, b, down, ptr_zero);
}

void	main_algo(char **a, char **b, int down, int parts, char **ptr_zero)
{
	//int	quarter;
	int	y;
	//int rest;
	
	//rest = (down - 1) % parts;
	// printf("rest = %d\n", rest);
 	y = 0;
	//quarter = 0;
	while (y < parts)
	{
		if (y < parts - 1)
			push_quarter(a, b, down, parts, ptr_zero);
		else
			reverse_push_quarter(a, b, down, ptr_zero);
		sort_quarter(a, b, down, ptr_zero);
		//printf("quart = %d\n", quarter);
		y++;
	}
}

 int main(int ac, char **av)
 {
	char **a;
	char **b;
	// int ac = 8;
	// char *tab[8] = {"a.out", "2", "3", "4", "1", "5", "0", "13"};
	int i = 0;
	char *ptr_zero;

  
	ptr_zero = malloc(sizeof(char));
	ptr_zero[0] = '\0';
	//printf("ptr[%p] = %s\n", ptr_zero, ptr_zero);

	//int *sort;

	//printf("\nvaleur de AC : %d\n", ac);
	a = init_stack_a(av, &ac);
	b = init_stack_b(ac, &ptr_zero);
	// printf("ptr[%p] = %s\n", ptr_zero, ptr_zero);
	// while (i < ac)
	// {
	// 	printf("tabA[%d] = %s (len[%ld]) // tabB = %s (len[])\n", i, a[i], ft_strlen(b[i]), b[i]);
	// 	i++;
	// }

	if (!swap_checker(a, ac) || is_sorted(a, ac))
	{
		if (!swap_checker(a, ac))
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	
	// sort = sort_tab(a, ac);
	// for (i = 0; i < ac; i++)
	// 	printf("tabA[%d] = %s // tabSORT[%d] = %d\n", i, a[i], i, sort[i]);
	// print_stack(a, b, ac);


	// printf("mitier = %d\n", is_in_midtier(sort, ac, 1));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, top(a, ac)));
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// printf("tabs_down = %d\n", near_down_tabs(a, sort, ac));
	// printf("tabs_top = %d\n", near_top_tabs(a, sort, ac));
	// printf("total = %d\n", near_top_tabs(a, sort, ac) - near_down_tabs(a, sort, ac));

	// printf("mitier = %d\n", is_in_midtier(sort, ac, ft_atoi(a[top(a, ac)])));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, top(a, ac)));
	// print_stack(a, b, ac);

	// push_b(a, b, ac);
	// printf("mitier = %d\n", is_in_midtier(sort, ac, ft_atoi(a[top(a, ac)])));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, top(a, ac)));
	//  printf("bef = %lld\n", ft_atoi(a[top(a, ac)]));
	//  push_b(a, b, ac);
	//  printf("bef = %lld\n", ft_atoi(a[top(a, ac)]));
	// printf("valeur de AC apres init : %d\n", ac);
	// printf("Minimal value : %d\n", minimal_value(a, ac));
	// printf("Maximal value : %d\n\n", maximal_value(a, ac));
	if (ac < 5)
		three_numbers(a, ac);

	else if (ac == 6)
		five_numbers(a, b, ac, &ptr_zero);
	else if (ac < 200)
		main_algo(a, b, ac, 4, &ptr_zero);
	else
		main_algo(a, b, ac, 8, &ptr_zero);
	// print_stack(a, b, ac);
	i = 0;
	free(ptr_zero);
	while (i < ac)
	{
		free(a[i]);
		//free(b[i]);
		i++;
	}
	free(a);
	free(b);
	//printf("near_down = %d\n", near_down(b, 2, ac));
 	return (0);
 }
