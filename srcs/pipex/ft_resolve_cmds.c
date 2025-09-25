/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/25 19:22:38 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		ft_safe_exit(char *m, int status, t_dlist *list, int **pipes);

void	ft_resolve_cmds(t_dlist *lst, int **pips, t_shrd *shrd)
{
	size_t	i;
	t_cmd	*cmd;
	t_dnode	*pivot;

	i = 1;
	pivot = lst->head;
	if (shrd->ishdoc)
		ft_handler_heredoc(shrd->argv[2], pips[0]);
	else
		ft_handler_infile(shrd->argv[1], pips[0]);
	while (pivot)
	{
		cmd = (t_cmd *)pivot->data;
		if (cmd->status != 0)
			ft_safe_exit(cmd->xcmd[0], cmd->status, lst, pips);
		if (pivot == lst->tail)
			ft_last_execproc(cmd, pips, shrd);
		else
			ft_execproc(cmd, pips, i, shrd);
		i++;
		pivot = pivot->next;
	}
}

static void	ft_safe_exit(char *m, int status, t_dlist *list, int **pipes)
{
	perror(m);
	ft_clean_dlist(list, ft_clean_cmd);
	ft_clean_tab((void **)pipes);
	exit(status);
}
