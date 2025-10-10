/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_execproc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:04:11 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:47:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_last_execproc(t_cmd *cmd, int **pips, t_share *shrd)
{
	int	last;

	last = shrd->argc - 3 - 1;
	if (shrd->ishdoc)
		last = shrd->argc - 4 - 1;
	shrd->outfile_fd = ft_handler_outfile(shrd);
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(pips[last][0], STDIN_FILENO);
		dup2(shrd->outfile_fd, STDOUT_FILENO);
		close(pips[last][0]);
		close(shrd->outfile_fd);
		execve(cmd->pcmd, cmd->xcmd, shrd->envp);
		perror(cmd->xcmd[0]);
	}
}
