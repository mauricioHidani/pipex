/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:26:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/10 10:36:13 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd	*ft_build_cmd(char *in, char **paths);
static int		ft_begin_idx(t_bool ishdoc);

t_dlist	*ft_build_cmds(t_share *shrd)
{
	int		i;
	char	**paths;
	t_cmd	*cmd;
	t_dlist	*list;

	list = ft_create_dlist(NULL);
	if (!list)
	{
		perror("malloc");
		return (NULL);
	}
	paths = ft_extract_paths(shrd->envp);
	if (!paths)
		return (free(list), NULL);
	i = ft_begin_idx(shrd->ishdoc);
	while (i < (shrd->argc - 1))
	{
		cmd = ft_build_cmd(shrd->argv[i], paths);
		if (!cmd)
		{
			ft_clean_dlist(list, ft_clean_cmd);
			return (NULL);
		}
		ft_push_lst_dlist(list, cmd);
		cmd = NULL;
		i++;
	}
	ft_clean_tab((void **)paths);
	return (list);
}

static t_cmd	*ft_build_cmd(char *in, char **paths)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->pid = -1;
	cmd->status = 0;
	cmd->xcmd = ft_split_respecting_target(in, ' ', '\'');
	if (!cmd->xcmd)
	{
		free(cmd);
		return (NULL);
	}
	cmd->pcmd = ft_extract_pcmd(cmd->xcmd[0], paths, &cmd->status);
	if (!cmd->pcmd)
	{
		ft_clean_tab((void **)cmd->xcmd);
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

static int	ft_begin_idx(t_bool ishdoc)
{
	int	idx;

	idx = 2;
	if (ishdoc)
		idx = 3;
	return (idx);
}
