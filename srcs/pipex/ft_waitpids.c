/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpids.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:15:58 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 12:19:04 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_waitpids(t_dlist *lst)
{
	t_cmd	*cmd;
	t_dnode	*pivot;

	pivot = lst->head;
	while (pivot)
	{
		cmd = (t_cmd *)pivot->data;
		waitpid(cmd->pid, &cmd->status, 0);
		pivot = pivot->next;
	}
}
