/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:55:22 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/07 22:05:13 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "external_incs.h"
#include "libft.h"
#include "pipex.h"

static void	ft_sanitize(char **mtx)
{
	int	i;

	if (!mtx)
		return ;
	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

static char	**ft_getenv(const char **env)
{
	int		i;
	char	*tmp;
	char	**nenv;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (!env[i])
		exit(1);
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

static char	**ft_getcmd(const char *cmd, const char **env)
{
	int		i;
	char	*aux;
	char	*tmp;
	char	**ncmd;

	ncmd = ft_split(cmd, ' ');
	aux = ft_substr(ncmd[0], 0, ft_strlen(ncmd[0]));
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
	ft_sanitize(ncmd);
	return (NULL);
}

char	**ft_validcmd(const char *cmd, const char **env)
{
	char	**ncmd;
	char	**nenv;

	if (!cmd || !env)
		exit(1);
	nenv = ft_getenv(env);
	ncmd = ft_getcmd(cmd, (const char **)nenv);
	ft_sanitize(nenv);
	return (ncmd);
}
