/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/12 12:31:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_handle_fexit(t_cmd *cmd, t_dlist *lst, t_share *shr, int **pips);
static void	ft_close_all_pips_chk(int **pps);

void	ft_resolve_cmds(t_dlist *lst, int **pps, t_share *shr)
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
			ft_handle_fexit(cmd, lst, shr, pps);
		else if (pivot == lst->tail)
			ft_last_execproc(cmd, pps, shr);
		else
			ft_execproc(cmd, pps, i, shr);
		i++;
		pivot = pivot->next;
	}
}

static void	ft_close_all_pips_chk(int **pps)
{
	int	i;
	int	j;

	i = 0;
	while (pps[i])
	{
		j = 0;
		while (j < 2)
		{
			if (pps[i][j] != -1)
				close(pps[i][j]);
			j++;
		}
		i++;
	}
}

static void	ft_handle_fexit(t_cmd *cmd, t_dlist *lst, t_share *shr, int **pps)
{
	int	status;

	status = cmd->status;
	ft_putstr_fd(cmd->xcmd[0], STDERR_FILENO);
	if (cmd->status == 127)
		ft_putstrln_fd(": command not found", STDERR_FILENO);
	else if (cmd->status == 126)
		ft_putstrln_fd(": permission denied", STDERR_FILENO);
	cmd->pid = -1;
	ft_close_all_pips_chk(pps);
	ft_clean_all(shr, pps, lst);
	exit(status);
}
