/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:20:05 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/08 16:48:27 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	**ft_alloc_pipes(size_t size);
static int	*ft_alloc_pipe_fd(int **pipes);
static void	ft_close_safe_all_pipes(int **pipes, size_t size);

int	**ft_build_pipes(int argc, t_bool ishdoc)
{
	size_t	i;
	size_t	size;
	int		**pipes;

	size = argc - 3;
	if (ishdoc)
		size = argc - 4;
	pipes = ft_alloc_pipes(size);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < size)
	{
		pipes[i] = ft_alloc_pipe_fd(pipes);
		if (!pipes[i])
			return (NULL);
		i++;
	}
	pipes[i] = NULL;
	i = 0;
	while (i < size)
		if (pipe(pipes[i++]) == -1)
			ft_close_safe_all_pipes(pipes, size);
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
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	return (pipe_fd);
}

static void	ft_close_safe_all_pipes(int **pipes, size_t size)
{
	size_t	i;

	perror("pipe");
	i = 0;
	while (i < size)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
