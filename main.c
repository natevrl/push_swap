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

void	main_algo(char **a, char **b, int down)
{
	int i;
	
	if(swap_checker(a, down) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	i = 0;
	while (1)
	{
		
		if (ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down))
		{
			push_b(a, b, down);
			i++;
			if (isempty(a, down))
				break ;
		}
		if (!near_down(a, minimal_value(a, down), down))
		 	rotate_a(a, down);
		 else
			reverse_rotate_a(a, down);
		i++;
	}
	while (!isempty(b, down))
	{
		push_a(a, b, down);
		i++;
	}
	//printf("\nnombre doperations : %d\n\n", i);
}

 int main(int ac, char **av)
 {
	char **a;
	char **b;
	 
	//printf("\nvaleur de AC : %d\n", ac);
	a = init_stack_a(av, &ac);
	b = init_stack_b(ac);
	//printf("valeur de AC apres init : %d\n", ac);
	//printf("%d || %d\n\n", before_empty_case(a, ac), first_empty_case(a, ac));
	// printf("Minimal value : %d\n\n", minimal_value(a, ac));
	//print_stack(a, b, ac);
	 main_algo(a, b, ac);
	//print_stack(a, b, ac);

 	return (0);
 }
