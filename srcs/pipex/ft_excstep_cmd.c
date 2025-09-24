/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excstep_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:04:11 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 12:22:27 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_first_child(t_cmd *cmd, int **pips, t_shrd *shrd);

void	ft_exec_first_cmd(t_cmd *cmd, int **pips, t_shrd *shrd)
{
	if (shrd->ishdoc && pipe(pips[0]) == -1)
		return (perror("pipe"));
	if (pipe(pips[1]) == -1)
		return (perror("pipe"));
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("fork");
		return ;
	}
	if (cmd->pid == 0)
		ft_first_child(cmd, pips, shrd);
	else
	{
		close(pips[0][0]);
		if (shrd->ishdoc)
			ft_handler_heredoc(shrd->argv[2], pips[0]);
		else
			ft_handler_infile(shrd->argv[1], pips[0]);
		close(pips[0][1]);
		close(pips[1][1]);
	}
}

static void	ft_first_child(t_cmd *cmd, int **pips, t_shrd *shrd)
{
	close(pips[0][1]);
	close(pips[1][0]);
	dup2(pips[0][0], STDIN_FILENO);
	dup2(pips[1][1], STDOUT_FILENO);
	close(pips[0][0]);
	close(pips[1][1]);
	execve(cmd->pcmd, cmd->xcmd, shrd->envp);
	perror(cmd->xcmd[0]);
}

void	ft_exec_middle_cmd(t_cmd *cmd, int **pips, size_t idx, t_shrd *shrd)
{
	if (pipe(pips[idx]) == -1)
	{
		perror("pipe");
		return ;
	}
	cmd->pid = fork();
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

void	ft_exec_last_cmd(t_cmd *cmd, int **pips, t_shrd *shrd)
{
	int	last;
	int	outfile;

	last = shrd->argc - 4;
	if (shrd->ishdoc)
		last = shrd->argc - 5;
	outfile = ft_handler_outfile(shrd);
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		close(pips[last][1]);
		dup2(pips[last][0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pips[last][0]);
		close(outfile);
		execve(cmd->pcmd, cmd->xcmd, shrd->envp);
		perror(cmd->xcmd[0]);
	}
	shrd->outfile_fd = outfile;
}
