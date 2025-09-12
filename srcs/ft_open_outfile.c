/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_outfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:24:04 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/11 19:28:38 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	ft_open_outfile(int size, char **lst)
{
	int	oflag;
	int	fd;

	oflag = O_TRUNC;
	if (ft_strncmp(lst[1], HEREDOC, ft_strlen(HEREDOC)) == 0)
		oflag = O_APPEND;
	fd = open(lst[size - 1], O_CREAT | O_WRONLY | oflag, 0644);
	if (!fd)
		exit(ERROR);
	return (fd);
}
