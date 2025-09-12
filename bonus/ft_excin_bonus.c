/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:05:30 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/11 21:12:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static void	ft_excin_file(char **argv);
static void	ft_excin_heredoc(char **argv);

void	ft_excin_bonus(char **argv, int *prev_in_fd)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(ERROR);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (ft_strncmp(argv[1], HEREDOC, ft_strlen(HEREDOC)) == 0)
			ft_excin_heredoc(argv);
		else
			ft_excin_file(argv);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		*prev_in_fd = fd[0];
	}
}

static void	ft_excin_file(char **argv)
{
	char	*line;
	char	*tmp;
	int	fd_read;
	
	fd_read = open(argv[1], O_RDONLY);
	if (fd_read < 0)
		exit(ERROR);
	line = ft_get_next_line(fd_read);
	while (line != NULL)
	{
		ft_putstr_fd(line, STDOUT_FILENO);
		tmp = line;
		line = ft_get_next_line(fd_read);
		free(tmp);
	}
	close(fd_read);
	exit(SUCCESS);
}

static void	ft_excin_heredoc(char **argv)
{
	char	*line;
	char	*tmp;

	line = ft_get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, argv[2], (ft_strlen(argv[2]) - 1)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, STDOUT_FILENO);
		tmp = line;
		line = ft_get_next_line(STDIN_FILENO);
                free(tmp);
	}
	exit(SUCCESS);
}
