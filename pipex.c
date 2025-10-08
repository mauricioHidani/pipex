/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:56:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/08 15:36:23 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	ishdoc;
	t_shrd	*shared;
	int		**pipes;
	t_dlist	*command_lst;
	int		exit_status;

	if (argc < 5 || !argv || !envp)
		return (EXIT_FAILURE);
	ishdoc = 0;
	if (ft_strncmp(argv[1], HEREDOC, ft_strlen(argv[1])) == 0)
		ishdoc = 1;
	shared = ft_build_shrd(argc, argv, envp, ishdoc);
	pipes = ft_build_pipes(argc, ishdoc);
	command_lst = ft_build_cmds(shared);
	if (!shared || !pipes || !command_lst)
	{
		ft_clean_all(shared, pipes, command_lst);
		return (EXIT_FAILURE);
	}
	ft_resolve_cmds(command_lst, pipes, shared);
	ft_close_all(pipes, shared);
	ft_waitpids(command_lst, &exit_status);
	ft_clean_all(shared, pipes, command_lst);
	return (exit_status);
}
