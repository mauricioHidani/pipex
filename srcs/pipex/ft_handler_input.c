/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:54:56 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:38:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_handler_heredoc(char *eof, int *fd)
{
	char	*line;

	ft_putstr_fd("> ", STDOUT_FILENO);
	line = ft_get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, eof, ft_strlen(line) - 1) == 0)
		{
			free(line);
			line = NULL;
			break ;
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = NULL;
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = ft_get_next_line(STDIN_FILENO);
	}
	close(fd[1]);
}

void	ft_handler_infile(char *filename, int *fd)
{
	int		infile_fd;
	char	*line;

	infile_fd = open(filename, O_RDONLY);
	if (infile_fd < 0)
		return (perror("open"));
	line = ft_get_next_line(infile_fd);
	while (line != NULL)
	{
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = NULL;
		line = ft_get_next_line(infile_fd);
	}
	close(infile_fd);
	close(fd[1]);
}
