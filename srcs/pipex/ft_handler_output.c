/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 07:08:47 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:47:42 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_handler_outfile(t_share *shared)
{
	int		flag;
	int		outfile_fd;
	char	*filename;

	flag = O_TRUNC;
	if (shared->ishdoc)
		flag = O_APPEND;
	filename = shared->argv[shared->argc - 1];
	outfile_fd = open(filename, O_CREAT | O_WRONLY | flag, 0644);
	if (outfile_fd < 0)
	{
		perror("open");
		return (0);
	}
	return (outfile_fd);
}
