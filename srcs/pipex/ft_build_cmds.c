/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:26:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/12 13:19:44 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd	*ft_build_cmd(char *in, char **paths);
static int		ft_begin_idx(t_bool ishdoc);
static t_bool	ft_fill_list(t_share *share, t_dlist *list, char **paths);

t_dlist	*ft_build_cmds(t_share *share)
{
	char	**paths;
	t_dlist	*list;

	list = ft_create_dlist(NULL);
	if (!list)
	{
		perror("malloc");
		return (NULL);
	}
	paths = ft_extract_paths(share->envp);
	if (!paths)
	{
		free(list);
		return (NULL);
	}
	if (!ft_fill_list(share, list, paths))
		return (NULL);
	return (list);
}

static t_bool	ft_fill_list(t_share *share, t_dlist *list, char **paths)
{
	int		i;
	t_bool	check;
	t_cmd	*cmd;

	check = TRUE;
	i = ft_begin_idx(share->ishdoc);
	while (i < (share->argc - 1))
	{
		cmd = ft_build_cmd(share->argv[i], paths);
		if (!cmd)
		{
			ft_clean_dlist(list, ft_clean_cmd);
			check = FALSE;
		}
		ft_push_lst_dlist(list, cmd);
		cmd = NULL;
		i++;
	}
	ft_clean_tab((void **)paths);
	return (check);
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
