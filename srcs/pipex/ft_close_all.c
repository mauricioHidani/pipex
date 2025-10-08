/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:14:40 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/08 11:41:55 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(int **pipes, t_shrd *shrd)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = shrd->argc - 4;
	if (shrd->ishdoc)
		size = shrd->argc - 5;
	while (i < size)
	{
		close(pipes[i][0]);
		i++;
	}
	close(shrd->outfile_fd);
}
