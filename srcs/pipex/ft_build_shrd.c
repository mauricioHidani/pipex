/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_shrd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:11:51 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:47:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_share	*ft_build_shrd(int argc, char **argv, char **envp, t_bool ishdoc)
{
	t_share	*shared;

	shared = malloc(sizeof(t_share));
	if (!shared)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	shared->argc = argc;
	shared->argv = argv;
	shared->envp = envp;
	shared->ishdoc = ishdoc;
	shared->outfile_fd = -1;
	return (shared);
}
