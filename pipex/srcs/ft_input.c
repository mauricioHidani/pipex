/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:56:17 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/07 22:17:11 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external_incs.h"
#include "libft.h"
#include "pipex.h"

static char	*ft_getcontent(int fd, char *limiter)
{
	char	*tmp;
	char	*tmp1;
	char	*line;
	char	*content;

	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	while (line)
	{
		tmp = line;
		line = ft_reader(fd);
		if (line || (fd == STDIN_FILENO && ft_strcmp(line, limiter) != 0))
		{
			tmp1 = content;
			content = ft_strjoin(content, line);
			free(tmp1);
		}
		free(tmp);
	}
	return (free(tmp), free(tmp1), content);
}

char	*ft_input(char **tgts)
{
	int		fd;
	char	*limiter;

	if (ft_strcmp(tgts[1], HEREDOC_NAME) == 0)
	{
		limiter = ft_strjoin(tgts[2], "\n");
		fd = STDIN_FILENO;
	}
	else
		fd = open(tgts[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	return (free(limiter), ft_getcontent(fd, limiter));
}
