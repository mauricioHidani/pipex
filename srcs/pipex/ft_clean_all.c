/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:16:32 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:47:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean_all(t_share *shrd, int **pips, t_dlist *lst)
{
	if (shrd)
		free(shrd);
	if (pips)
		ft_clean_tab((void **)pips);
	if (lst)
		ft_clean_dlist(lst, ft_clean_cmd);
}
