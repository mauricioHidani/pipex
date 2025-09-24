/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:07:32 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/23 15:42:32 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_cmd(void *cmd)
{
	t_cmd	*ncmd;

	ncmd = (t_cmd *)cmd;
	ft_clean_tab((void **)ncmd->xcmd);
	free(ncmd->pcmd);
	free(ncmd);
}
