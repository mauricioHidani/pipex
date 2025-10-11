/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:56:46 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 09:03:33 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_validade_build(t_share *share, int **pipes, t_dlist *cmds);
static void	ft_resolve_input(t_share *share, int **pipes);

int	main(int argc, char **argv, char **envp)
{
	char	ishdoc;
	t_share	*share;
	int		**pipes;
	t_dlist	*commands;
	int		exit_status;

	if (argc < 5 || !argv || !envp)
		return (EXIT_FAILURE);
	ishdoc = 0;
	if (ft_strncmp(argv[1], HEREDOC, ft_strlen(argv[1])) == 0)
		ishdoc = 1;
	share = ft_build_shrd(argc, argv, envp, ishdoc);
	pipes = ft_build_pipes(argc, ishdoc);
	ft_resolve_input(share, pipes);
	commands = ft_build_cmds(share);
	ft_validade_build(share, pipes, commands);
	ft_resolve_cmds(commands, pipes, share);
	ft_close_all(pipes, share);
	ft_waitpids(commands, &exit_status);
	ft_clean_all(share, pipes, commands);
	return (exit_status);
}

static void	ft_validade_build(t_share *share, int **pipes, t_dlist *cmds)
{
	int	status_exit;

	status_exit = EXIT_FAILURE;
	if (!share || !pipes || !cmds)
	{
		ft_clean_all(share, pipes, cmds);
		exit(status_exit);
	}
}

static void	ft_resolve_input(t_share *share, int **pipes)
{
	if (share->ishdoc)
		ft_handler_heredoc(share->argv[2], pipes[0]);
	else
		ft_handler_infile(share->argv[1], pipes[0]);
}
