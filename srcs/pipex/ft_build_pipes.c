/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:20:05 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/23 18:51:56 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	**ft_alloc_pipes(size_t size);
static int	*ft_alloc_pipe_fd(int **pipes);

int	**ft_build_pipes(int argc, char ishdoc)
{
	size_t	i;
	size_t	size;
	int		**pipes;

	size = argc - 3;
	if (ishdoc)
		size = argc - 4;
	pipes = ft_alloc_pipes(size);
	if (!pipe)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = ft_alloc_pipe_fd(pipes);
		if (!pipes[i])
			return (NULL);
		i++;
	}
	return (pipes);
}

static int	**ft_alloc_pipes(size_t size)
{
	int	**pipes;

	pipes = ft_calloc(size + 1, sizeof(int *));
	if (!pipes)
	{
		perror("ft_calloc");
		return (NULL);
	}
	return (pipes);
}

static int	*ft_alloc_pipe_fd(int **pipes)
{
	int	*pipe_fd;

	pipe_fd = ft_calloc(2, sizeof(int));
	if (!pipe_fd)
	{
		perror("ft_calloc");
		ft_clean_tab((void **)pipes);
		return (NULL);
	}
	return (pipe_fd);
}
