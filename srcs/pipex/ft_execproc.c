/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:44:53 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 19:45:15 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execproc(t_cmd *cmd, int **pips, size_t idx, t_shrd *shrd)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		return ;
	}
	if (cmd->pid == 0)
	{
		close(pips[idx - 1][1]);
		close(pips[idx][0]);
		dup2(pips[idx - 1][0], STDIN_FILENO);
		dup2(pips[idx][1], STDOUT_FILENO);
		close(pips[idx - 1][0]);
		close(pips[idx][1]);
		execve(cmd->pcmd, cmd->xcmd, shrd->envp);
		perror(cmd->xcmd[0]);
	}
	close(pips[idx][1]);
}
