/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:15:38 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/06 13:34:51 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	char	*block;

	block = malloc(elementSize * elementCount);
	if (!block)
		return (NULL);
	block = ft_memset(block, 0, elementSize * elementCount);
	return (block);
}
