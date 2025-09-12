/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:45:23 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/12 17:36:12 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	prev_in_fd;

	if (argc < 5)
		return (ERROR);
	prev_in_fd = -1;
	ft_excin(argv, &prev_in_fd);
	i = 2;
	while (i < (argc - 2))
		ft_excprc(argv[i++], envp, &prev_in_fd);
	ft_excout(argc, argv, envp, &prev_in_fd);
	return (SUCCESS);
}
