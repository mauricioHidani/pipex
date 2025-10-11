/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:07:32 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 10:38:56 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_cmd(void *cmd)
{
	t_cmd	*ncmd;

	ncmd = (t_cmd *)cmd;
	if (ncmd->xcmd)
		ft_clean_tab((void **)ncmd->xcmd);
	if (ncmd->pcmd)
		free(ncmd->pcmd);
	free(ncmd);
}
