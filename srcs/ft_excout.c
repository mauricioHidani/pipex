/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:14:05 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/12 10:46:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_excout(int argc, char **argv, char **envp, int *prev_in_fd)
{
	int		fd_open;
	char	**cmd;
	pid_t	pid;

	fd_open = ft_open_outfile(argc, argv);
	cmd = ft_extract_cmd(argv[argc - 2], envp);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(*prev_in_fd, STDIN_FILENO) < 0)
			close(*prev_in_fd);
		if (dup2(fd_open, STDOUT_FILENO) < 0)
			close(fd_open);
		close(*prev_in_fd);
		close(fd_open);
		execve(cmd[0], cmd, envp);
		exit(ERROR);
	}
	else
	{
		close(*prev_in_fd);
		close(fd_open);
		waitpid(pid, NULL, 0);
		ft_sanatize_mtx(cmd);
	}
}
