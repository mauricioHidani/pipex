/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 09:30:58 by mhidani           #+#    #+#             */
/*   Updated: 2025/07/25 12:01:59 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t length, size_t mem_size)
{
	void	*allocated;

	if (length == 0 || mem_size == 0)
		return (malloc(1));
	if (length != 0 && mem_size > (size_t)-1 / length)
		return (NULL);
	allocated = malloc(length * mem_size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, length * mem_size);
	return (allocated);
}
