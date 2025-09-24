/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpids.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:15:58 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 19:31:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_waitpids(t_dlist *lst, int *status)
{
	t_cmd	*cmd;
	t_dnode	*pivot;

	pivot = lst->head;
	while (pivot)
	{
		cmd = (t_cmd *)pivot->data;
		if (waitpid(cmd->pid, status, 0) == -1)
			break ;
		pivot = pivot->next;
	}
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		*status = 128 + WTERMSIG(*status);
}
