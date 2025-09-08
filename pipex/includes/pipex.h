/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:41:36 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/07 22:05:29 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Defining a name for HereDoc used in its identification
# ifndef HEREDOC_NAME
#  define HEREDOC_NAME "here_doc"
# endif

// Defining a Buffer size to read input
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef enum e_tip
{
	e_success,
	e_error
}	t_tip;

void	ft_pipex(int argc, char **argv, char **envp);
void	ft_output(char *output, char *content);
char	*ft_input(char **targets);
char	*ft_reader(int fd);
char	**ft_validcmd(const char *cmd, const char **env);

#endif
