/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 02:36:34 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_pipex(t_pipex *pipex, int cmds_size, char **cmds, char **envp)
{
	int	i;
	
	i = 1;
	while (++i < cmds_size - 1)
	{
		pipex->cmdargs = spliter(cmds[i]);
		pipex->path = pathfinder(cmdargs[0], envp);
	}
}

static int	start_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->path = NULL;
	pipex->cmdargs = NULL;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile < 0 || pipex->outfile < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	if (start_pipex(&pipex, argc, argv, envp) != 0)
		return (write(2, ".ERROR: start_pipex.\n", 20));
	if (ft_pipex(&pipex, argc, argv, envp) != 0)
		return (write(2, ".ERROR: ft_pipex.\n", 18));
	return (0);
}
