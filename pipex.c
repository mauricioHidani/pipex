/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:56:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 12:24:08 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	ishdoc;
	t_shrd	*shared;
	int		**pipes;
	t_dlist	*list;

	if (argc < 5 || !argv || !envp)
		return (EXIT_FAILURE);
	ishdoc = 0;
	if (ft_strncmp(argv[1], HEREDOC, ft_strlen(argv[1])) == 0)
		ishdoc = 1;
	shared = ft_build_shrd(argc, argv, envp, ishdoc);
	pipes = ft_build_pipes(argc, ishdoc);
	list = ft_build_cmds(shared);
	ft_exec_cmds(list, pipes, shared);
	ft_close_all(pipes, shared);
	ft_waitpids(list);
	ft_clean_all(shared, pipes, list);
	return (EXIT_SUCCESS);
}
