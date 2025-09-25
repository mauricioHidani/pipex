/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:44:34 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/25 11:55:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char		*ft_find_path(char **envp);
static void		ft_join_brackage(char **paths);

char	*ft_extract_pcmd(char *cmd, char **paths, int *status)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	*status = 0x00;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			*status = 0x80;
			break ;
		}
		if (access(tmp, F_OK) != 0)
			*status = *status | 0x01;
		else if (access(tmp, X_OK) != 0)
			*status = *status | 0x02;
		free(tmp);
		tmp = NULL;
		i++;
	}
	*status = 0x80 - *status;
	return (tmp);
}

char	**ft_extract_paths(char **envp)
{
	char	*environment_path;
	char	**paths;

	environment_path = ft_find_path(envp);
	paths = ft_split(environment_path, ':');
	if (!paths)
		return (NULL);
	free(environment_path);
	environment_path = NULL;
	ft_join_brackage(paths);
	return (paths);
}

static char	*ft_find_path(char **envp)
{
	char	*path;
	size_t	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	return (path);
}

static void	ft_join_brackage(char **paths)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (paths[i])
	{
		len = ft_strlen(paths[i]);
		if (paths[i][len - 1] != '/')
		{
			tmp = paths[i];
			paths[i] = ft_strjoin(tmp, "/");
			free(tmp);
			if (!paths[i])
			{
				ft_clean_tab((void **)paths);
				return ;
			}
			tmp = NULL;
		}
		i++;
	}
}
