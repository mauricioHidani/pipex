/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excprc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:10:02 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/11 21:10:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_excprc(char *cmd, char **envp, int *prev_in_fd)
{
	int	fd[2];
	char	**cmdx;
	pid_t	pid;

	if (pipe(fd) < 0)
		exit(ERROR);
	cmdx = ft_extract_cmd(cmd, envp);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
        	dup2(*prev_in_fd, STDIN_FILENO);
        	dup2(fd[1], STDOUT_FILENO);
        	close(*prev_in_fd);
        	close(fd[1]);
		execve(cmdx[0], cmdx, envp);
		exit(ERROR);
	}
	else
        {
            close(*prev_in_fd);
            close(fd[1]);
            waitpid(pid, NULL, 0);
            *prev_in_fd = fd[0];
        }
}
