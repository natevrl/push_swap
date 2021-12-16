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


void	main_algo(char **a, char **b, int down)
{
	while (1)
	{
		if (ft_atoi(a[before_empty_case(a, down)]) == minimal_value(a, down))
		{
			push_b(a, b, down);
			if (isempty(a, down))
				break ;
		}
		rotate_a(a, down);
	}
	while (!isempty(b, down))
		push_a(a, b, down);
}

 int main(int ac, char **av)
 {
	char **a;
	char **b;
	 
	printf("valeur de AC : %d\n", ac);
	a = init_stack_a(av, ac);
	b = init_stack_b(ac);
	printf("%d || %d\n\n", before_empty_case(a, ac), first_empty_case(a, ac));
	printf("Minimal value : %d\n\n", minimal_value(a, ac));
	print_stack(a, b, ac);
	main_algo(a, b, ac);
	print_stack(a, b, ac);

 	return (0);
 }
