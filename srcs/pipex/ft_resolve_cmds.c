/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 11:16:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_handle_cmd_statusfx(t_cmd *cmd);

void	ft_resolve_cmds(t_dlist *lst, int **pips, t_share *shrd)
{
	size_t	i;
	t_cmd	*cmd;
	t_dnode	*pivot;

	i = 1;
	pivot = lst->head;
	while (pivot)
	{
		cmd = (t_cmd *)pivot->data;
		if (cmd->status != 0)
			ft_handle_cmd_statusfx(cmd);
		else if (pivot == lst->tail)
			ft_last_execproc(cmd, pips, shrd);
		else
			ft_execproc(cmd, pips, i, shrd);
		i++;
		pivot = pivot->next;
	}
}

static void	ft_handle_cmd_statusfx(t_cmd *cmd)
{
	ft_putstr_fd(cmd->xcmd[0], STDERR_FILENO);
	if (cmd->status == 127)
		ft_putstrln_fd(": command not found", STDERR_FILENO);
	else if (cmd->status == 126)
		ft_putstrln_fd(": permission denied", STDERR_FILENO);
	cmd->pid = -1;
}
