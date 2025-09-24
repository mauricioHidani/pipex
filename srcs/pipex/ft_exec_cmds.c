/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:49:45 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 12:20:48 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		ft_safe_exit(char *m, int status, t_dlist *list, int **pipes);

void	ft_exec_cmds(t_dlist *lst, int **pips, t_shrd *shrd)
{
	size_t	i;
	t_cmd	*cmd;
	t_dnode	*pivot;
	int		outfile;

	i = 1;
	pivot = lst->head;
	while (pivot)
	{
		cmd = (t_cmd *)pivot->data;
		if (cmd->status != 0)
			ft_safe_exit(cmd->xcmd[0], cmd->status, lst, pips);
		if (pivot == lst->head)
			ft_exec_first_cmd(cmd, pips, shrd);
		else if (pivot == lst->tail)
			ft_exec_last_cmd(cmd, pips, shrd);
		else
			ft_exec_middle_cmd(cmd, pips, i, shrd);
		i++;
		pivot = pivot->next;
	}
	close(outfile);
}

static void	ft_safe_exit(char *m, int status, t_dlist *list, int **pipes)
{
	perror(m);
	ft_clean_dlist(list, ft_clean_cmd);
	ft_clean_tab((void **)pipes);
	exit(status);
}
