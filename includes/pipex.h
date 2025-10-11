/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:57:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 08:59:15 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "dlist.h"

# ifndef HEREDOC
#  define HEREDOC "here_doc"
# endif

# define TRUE 0x01
# define FALSE 0x00

typedef char	t_bool;

typedef struct s_share
{
	int		argc;
	char	**argv;
	char	**envp;
	t_bool	ishdoc;
	int		outfile_fd;
}	t_share;

typedef struct s_command
{
	pid_t	pid;
	char	**xcmd;
	char	*pcmd;
	int		status;
}	t_cmd;

t_share	*ft_build_shrd(int argc, char **argv, char **envp, t_bool ishdoc);
int		**ft_build_pipes(int argc, t_bool ishdoc);
t_dlist	*ft_build_cmds(t_share *shared);

void	ft_resolve_cmds(t_dlist *cmds, int **pips, t_share *shrd);
void	ft_execproc(t_cmd *cmd, int **pips, size_t idx, t_share *shrd);
void	ft_last_execproc(t_cmd *cmd, int **pips, t_share *shared);

void	ft_handler_heredoc(char *eof, int *fd);
void	ft_handler_infile(char *filename, int *fd);
int		ft_handler_outfile(t_share *shared);

char	**ft_extract_paths(char **envp);
char	*ft_extract_pcmd(char *cmd, char **paths, int *status);

void	ft_waitpids(t_dlist *lst, int *status);
void	ft_close_all(int **pipes, t_share *shrd);
void	ft_clean_all(t_share *shrd, int **pips, t_dlist *lst);
void	ft_clean_cmd(void *cmd);

#endif