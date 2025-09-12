/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:14:15 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/12 10:40:55 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "external_incs.h"
# include "definitions.h"

// Child execute proccess middle
void	ft_excprc(char *cmd, char **envp, int *prev_in_fd);

// Child execute proccess beginning
void	ft_excin(char **argv, int *prev_in_fd);

// Child execute proccess end
void	ft_excout(int argc, char **argv, char **envp, int *prev_in_fd);
int		ft_open_outfile(int size, char **lst);

// Auxiliary functions
char	**ft_extract_cmd(char *s, char **env);
void	ft_sanatize_mtx(char **cmd);

#endif
