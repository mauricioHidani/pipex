/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:26:58 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/12 11:01:40 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static char	**ft_get_env(char **env);
static void	ft_clean_str(char **ncmd);
static char	**ft_get_cmd(char *cmd, char **env);

char	**ft_extract_cmd(char *s, char **env)
{
	char	**ncmd;
	char	**nenv;

	if (!s || !env)
		exit(1);
	nenv = ft_get_env(env);
	ncmd = ft_get_cmd(s, nenv);
	if (!ncmd)
	{
		ft_sanatize_mtx(nenv);
		perror("ft_extract_cmd");
		exit(ERROR);
	}
	ft_sanatize_mtx(nenv);
	return (ncmd);
}

static char	**ft_get_env(char **env)
{
	int		i;
	char	*tmp;
	char	**nenv;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (!env[i])
	{
		perror("ft_get_env");
		exit(ERROR);
	}
	tmp = ft_substr(env[i], 5, ft_strlen(env[i]));
	nenv = ft_split(tmp, ':');
	free(tmp);
	i = 0;
	while (nenv[i])
	{
		tmp = (char *)nenv[i];
		nenv[i] = ft_strjoin(nenv[i], "/");
		free(tmp);
		i++;
	}
	return (nenv);
}

static void	ft_clean_str(char **ncmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ncmd[i] != NULL)
	{
		tmp = ncmd[i];
		ncmd[i] = ft_strtrim(ncmd[i], "'\"");
		free(tmp);
		i++;
	}
}

static char	**ft_get_cmd(char *cmd, char **env)
{
	int		i;
	char	*aux;
	char	*tmp;
	char	**ncmd;

	ncmd = ft_split(cmd, ' ');
	ft_clean_str(ncmd);
	aux = ft_strdup(ncmd[0]);
	i = 0;
	while (env[i])
	{
		tmp = ncmd[0];
		ncmd[0] = ft_strjoin(env[i], aux);
		if (access(ncmd[0], X_OK) == 0)
			return (free(aux), free(tmp), ncmd);
		free(tmp);
		i++;
	}
	free(aux);
	ft_sanatize_mtx(ncmd);
	perror("ft_get_cmd");
	return (NULL);
}
