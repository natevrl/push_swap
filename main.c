/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:36:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/16 21:09:49y nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	main_algo(char **a, char **b, int down)
// {
// 	int i;
	
// 	if(swap_checker(a, down) == 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return ;
// 	}
// 	i = 0;
// 	while (1)
// 	{
// 		if (ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down))
// 		{
// 			push_b(a, b, down);
// 			i++;
// 			if (isempty(a, down))
// 				break ;
// 		}
// 		rotate_a(a, down);
// 		i++;
// 	}
// 	while (!isempty(b, down))
// 	{
// 		push_a(a, b, down);
// 		i++;
// 	}
// 	//printf("\nnombre doperations : %d\n\n", i);
// }

void	three_numbers(char **a, int down)
{
	if(swap_checker(a, down) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	while (1)
	{
		if (ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down) 
		|| ft_atoi(a[down - 2]) == maximal_value(a, down))
		{
			if (ft_atoi(a[down - 2]) == maximal_value(a, down) 
			&& ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down))
				return ;
			else if (ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down))
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

	//printf("\nnombre doperations : %d\n\n", i);
}

// void	five_numbers(char **a, int down)
// {

// }

// void	main_algo(char **a, char **b, int down)
// {
// 	int i;
	
// 	if(swap_checker(a, down) == 0)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return ;
// 	}
// 	i = 0;
// 	while (1)
// 	{
		
// 		if (ft_atoi(a[before_empty_case(a, down)]) == maximal_value(a, down))
// 		{
// 			push_b(a, b, down);
// 			i++;
// 			if (isempty(a, down))
// 				break ;
// 		}
// 		if (!near_down(a, maximal_value(a, down), down))
// 		 	rotate_a(a, down);
// 		 else
// 			reverse_rotate_a(a, down);
// 		i++;
// 	}
// 	while (!isempty(b, down))
// 	{
// 		push_a(a, b, down);
// 		i++;
// 	}
// 	//printf("\nnombre doperations : %d\n\n", i);
// }


void	big_stack_sorting(char **a, char **b, int down)
{
	if(swap_checker(a, down) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	while (!isempty(a, down))
	{
		while (!isempty(b, down) && ft_atoi(b[before_empty_case(b, down)]) > ft_atoi(a[before_empty_case(a, down)]))
		{
			push_a(a, b, down);
			swap_a(a, down);
		}
		push_b(a, b, down);
	}
	while (!isempty(b, down))
		push_a(a, b, down);

	//printf("\nnombre doperations : %d\n\n", i);
}

void	main_algo(char **a, char **b, int down)
{
	int *sort;
	int quarter;
	int i;
	//int compteur;

	if(swap_checker(a, down) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	sort = sort_tab(a, down);
	quarter = 0;
// trie et push par 
	i = 0;
	while (i <= (down - 2))
	{
		if (is_in_quarter(sort, down, ft_atoi(a[before_empty_case(a, down)]), quarter))
		{
			push_b(a, b, down);
			//compteur++;
		}
		// reussir a savoir si une des valeurs du tab_sort est plus proche du haut ou de bas, a chaque coups
		else
			rotate_a(a, down);
		i++;
	}

	while (!isempty(b, down))
	{
		if (ft_atoi(b[before_empty_case(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down);
		}
		else if (near_down(b, maximal_value(b, down), down))
			reverse_rotate_b(b, down);
		else
		 	rotate_b(b, down);
	}

	quarter += (down - 2) / 4;
	i = 0;
	while (i <= (down - 2))
	{
		if (is_in_quarter(sort, down, ft_atoi(a[before_empty_case(a, down)]), quarter))
		{
			push_b(a, b, down);
			//compteur++;
		}
		// reussir a savoir si une des valeurs du tab_sort est plus proche du haut ou de bas, a chaque coups
		else
			rotate_a(a, down);
		i++;
	}

	while (!isempty(b, down))
	{
		if (ft_atoi(b[before_empty_case(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down);
		}
		else if (near_down(b, maximal_value(b, down), down))
			reverse_rotate_b(b, down);
		else
		 	rotate_b(b, down);
	}



	quarter += (down - 2) / 4;

	i = 0;
	while (i <= (down - 2))
	{
		if (is_in_quarter(sort, down, ft_atoi(a[before_empty_case(a, down)]), quarter))
		{
			push_b(a, b, down);
			//compteur++;
		}
		// reussir a savoir si une des valeurs du tab_sort est plus proche du haut ou de bas, a chaque coups
		else
			rotate_a(a, down);
		i++;
	}

	while (!isempty(b, down))
	{
		if (ft_atoi(b[before_empty_case(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down);
		}
		else if (near_down(b, maximal_value(b, down), down))
			reverse_rotate_b(b, down);
		else
		 	rotate_b(b, down);
	}



	quarter += (down - 2) / 4;
	i = 0;
	while (i <= (down - 3) / 4)
	{
		reverse_rotate_a(a, down);
		push_b(a, b, down);

		i++;
	}

	while (!isempty(b, down))
	{
		if (ft_atoi(b[before_empty_case(b, down)]) == maximal_value(b, down))
		{
			push_a(a, b, down);
		}
		else if (near_down(b, maximal_value(b, down), down))
			reverse_rotate_b(b, down);
		else
		 	rotate_b(b, down);
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

	//  sort = sort_tab(a, ac);
	// for (i = 0; i < 5; i++)
	// 	printf(" tab[%d] = %d\n", i, sort[i]);
	// print_stack(a, b, ac);
	// printf("mitier = %d\n", is_in_midtier(sort, ac, 1));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, before_empty_case(a, ac)));
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// push_b(a, b, ac);
	// printf("tabs_down = %d\n", near_down_tabs(a, sort, ac));
	// printf("tabs_top = %d\n", near_top_tabs(a, sort, ac));
	// printf("total = %d\n", near_top_tabs(a, sort, ac) - near_down_tabs(a, sort, ac));

	// printf("mitier = %d\n", is_in_midtier(sort, ac, ft_atoi(a[before_empty_case(a, ac)])));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, before_empty_case(a, ac)));
	// print_stack(a, b, ac);

	// push_b(a, b, ac);
	// printf("mitier = %d\n", is_in_midtier(sort, ac, ft_atoi(a[before_empty_case(a, ac)])));
	// printf("there is midtier : %d\n", there_is_midtier(sort, a, ac, before_empty_case(a, ac)));
	//  printf("bef = %lld\n", ft_atoi(a[before_empty_case(a, ac)]));
	//  push_b(a, b, ac);
	//  printf("bef = %lld\n", ft_atoi(a[before_empty_case(a, ac)]));
	// printf("valeur de AC apres init : %d\n", ac);
	// printf("Minimal value : %d\n", minimal_value(a, ac));
	// printf("Maximal value : %d\n\n", maximal_value(a, ac));
	if (ac < 5)
		three_numbers(a, ac);
	// else if (ac == 5 || ac == 6)

	else
	{
		// big_stack_sorting(a, b, ac);
		  main_algo(a, b, ac);
	}
	//printf("near_down = %d\n", near_down(b, 2, ac));

	//print_stack(a, b, ac);
 	return (0);
 }
