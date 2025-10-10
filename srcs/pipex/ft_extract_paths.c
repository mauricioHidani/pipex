/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:44:34 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 11:23:16 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char		*ft_find_path(char **envp);
static void		ft_join_brackage(char **paths);
static char		*ft_find_fxok_cmd(char *cmd, char *fpath, int *status);

char	*ft_extract_pcmd(char *cmd, char **paths, int *status)
{
	char	*tmp;
	char	*fullpath;
	size_t	i;

	if (!paths)
		return (NULL);
	fullpath = NULL;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (!tmp)
			return (NULL);
		fullpath = ft_find_fxok_cmd(cmd, tmp, status);
		if (fullpath)
			break ;
		free(tmp);
		i++;
	}
	if (!fullpath)
	{
		*status = 127;
		return (ft_strdup(cmd));
	}
	return (fullpath);
}

static char	*ft_find_fxok_cmd(char *cmd, char *fpath, int *status)
{
	if (access(fpath, F_OK) == 0)
	{
		if (access(fpath, X_OK) == 0)
		{
			*status = 0;
			return (fpath);
		}
		else
		{
			*status = 126;
			free(fpath);
			return (ft_strdup(cmd));
		}
	}
	return (NULL);
}

char	**ft_extract_paths(char **envp)
{
	char	*environment_path;
	char	**paths;

	environment_path = ft_find_path(envp);
	if (!environment_path)
		return (NULL);
	paths = ft_split(environment_path, ':');
	free(environment_path);
	if (!paths)
		return (NULL);
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
