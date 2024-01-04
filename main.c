/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 16:55:14 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closer(t_pipex *pipex, int option1, int option2)
{
	close(pipex->fd[option1]);
	dup2(pipex->fd[option2], option2);
	close(pipex->fd[option2]);
}

static void	cmd_controller(t_pipex *pipex, char *cmd)
{
	if (pipex->pid == 0)
	{
		closer(&pipex, 0, 1);
		pipex->cmdargs = spliter(cmd);
		pipex->pathfinder(&pipex);
		if (access(pipex->path, F_OK | X_OK) != 0
			&& ft_strchr(pipex->cmdargs[0], '/'))
		{
			cleaner_matrix(pipex->cmdargs);
			return (write(2, ".ERROR: Command Not Found.\n", 27));
		}
		execve(pipex->path, pipex->cmdargs, pipex->envi);
	}
	else
		closer(&pipex, 1, 0);
}
static int	ft_pipex(t_pipex *pipex, int cmds_size, char **cmds)
{
	int	i;
	
	i = 1;
	dup2(infile, 0);
	while (++i < cmds_size - 2)
		cmd_controller(&pipex, cmds[i]);
	closer(&pipex, 0, 1);
	pipex->cmdargs = spliter(cmds[i]);
	pipex->pathfinder(&pipex);
	if (access(pipex->path, F_OK | X_OK) != 0
		&& ft_strchr(pipex->cmdargs[0], '/'))
	{
		cleaner_matrix(pipex->cmdargs);
		return (write(2, ".ERROR: Command Not Found.\n", 27);
	}
	execve(pipex->path, pipex->cmdargs, envp);
	waitpid(-1, NULL, 0);
}

static int	start_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->path = NULL;
	pipex->cmdargs = NULL;
	pipex->envi = envp;
	pipex->pid = fork();
	pipex->pipe = pipe(pipex->pipe);
	pipex->fd[0] = open(argv[1], O_RDONLY);
	pipex->fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 00700);
	if (pipex->fd[0] < 0 || pipex->fd[1] < 0)
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
	if (ft_pipex(&pipex, argc, argv) != 0)
		return (write(2, ".ERROR: ft_pipex.\n", 18));
	return (0);
}
