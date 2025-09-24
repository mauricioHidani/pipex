/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:26:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/24 19:28:59 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmd	*ft_build_cmd(char *in, char **paths);

t_dlist	*ft_build_cmds(t_shrd *shared)
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
	paths = ft_extract_paths(shared->envp);
	i = 2;
	if (shared->ishdoc)
		i = 3;
	while (i < (shared->argc - 1))
	{
		cmd = ft_build_cmd(shared->argv[i], paths);
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
	cmd->pcmd = ft_extract_pcmd(cmd->xcmd[0], paths, &cmd->status);
	return (cmd);
}
