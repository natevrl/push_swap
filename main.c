/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:07:37 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:40 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	three_numbers(char **a, int down)
{
	while (1)
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

void	big_stack_sorting(char **a, char **b, int down)
{
	while (!isempty(a, down))
	{
		while (!isempty(b, down)
			&& ft_atoi(b[top(b, down)]) > ft_atoi(a[top(a, down)]))
		{
			push_a(a, b, down);
			swap_a(a, down);
		}
		push_b(a, b, down);
	}
	while (!isempty(b, down))
		push_a(a, b, down);
}

void	push_quarter(char **a, char **b, int down, int quarter, int parts)
{
	int	i;
	int	*sort;

	sort = sort_tab(a, down);
	i = 0;
	while (i <= (down - 2))
	{
		if (is_in_parts(sort, down, ft_atoi(a[top(a, down)]), quarter, parts))
			push_b(a, b, down);
		else
		{
			if (ft_atoi(b[top(b, down)]) != maximal_value(b, down))
				rotate_rr(a, b, down);
			else
				rotate_a(a, down);
		}
		i++;
	}
}

void	reverse_push_quarter(char **a, char **b, int down)
{
	while (ft_atoi(a[down - 2]) != maximal_value(a, down))
	{
		if (ft_atoi(b[top(b, down)]) != maximal_value(b, down))
			reverse_rotate_rr(a, b, down);
		else
			reverse_rotate_a(a, down);
		push_b(a, b, down);
	}
}

void	sort_quarter(char **a, char **b, int down)
{
	while (!isempty(b, down))
	{
		if (ft_atoi(b[top(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down);
		}
		else if (near_top(b, maximal_value(b, down), down) >= 0)
			rotate_b(b, down);
		else
			reverse_rotate_b(b, down);
	}
}

void	main_algo(char **a, char **b, int down, int parts)
{
	int	quarter;
	int	y;

	y = 0;
	quarter = 0;
	while (y < parts)
	{
		if (y < parts - 1)
			push_quarter(a, b, down, quarter, parts);
		else
			reverse_push_quarter(a, b, down);
		sort_quarter(a, b, down);
		quarter += ((down - 2) / parts) + 1;
		y++;
	}
}

 int main(int ac , char **av)
 {
	char **a;
	char **b;
	//int ac;
	// int *sort;
	// int i;

	// ac = 6;
	// char *tab[11] = {"a.out", "2", "3", "4", "1", "5"};
	//printf("\nvaleur de AC : %d\n", ac);
	a = init_stack_a(av, &ac);
	b = init_stack_b(ac);
	if (is_sorted(a, ac))
	if (swap_checker(a, ac) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	
	//  sort = sort_tab(a, ac);
	// for (i = 0; i < 5; i++)
	// 	printf(" tab[%d] = %d\n", i, sort[i]);
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
	else if (ac < 200)
		main_algo(a, b, ac, 4);
	else
		main_algo(a, b, ac, 8);
	//printf("near_down = %d\n", near_down(b, 2, ac));
	//print_stack(a, b, ac);
 	return (0);
 }
