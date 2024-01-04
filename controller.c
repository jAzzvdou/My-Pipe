/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:19:47 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 18:50:37 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleaner_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

static void	closer(t_pipex *pipex, int option1, int option2)
{
	close(pipex->pipe[option1]);
	dup2(pipex->pipe[option2], option2);
	close(pipex->pipe[option2]);
}

static void	executer(t_pipex *pipex, char *cmd)
{
	closer(pipex, 0, 1);
	pipex->cmdargs = spliter(cmd);
	pipex->path = pathfinder(pipex);
	if (access(pipex->path, F_OK | X_OK) != 0
		&& ft_strchr(pipex->cmdargs[0], '/'))
	{
		perror(".ERROR: Command Not Found.\n");
		cleaner_matrix(pipex->cmdargs);
		exit(1);
	}
	write(1, ".zero.\n", 7); //PROBLEMA NO EXECVE
	execve(pipex->path, pipex->cmdargs, pipex->envi);
	write(2, ".ERROR: Command Not Found.\n", 27);
	exit(1);
}

static void	process_controller(t_pipex *pipex, char *cmd)
{
	pipex->pid = fork();
	pipe(pipex->pipe);
	if (pipex->pid == 0)
		executer(pipex, cmd);
	else
		closer(pipex, 1, 0);
}

void	cmd_controller(t_pipex *pipex, int cmds_size, char **cmds)
{
	int	i;

	i = 1;
	dup2(pipex->fd[0], 0);
	while (++i < cmds_size - 2)
		process_controller(pipex, cmds[i]);
	executer(pipex, cmds[i]);
	waitpid(-1, NULL, 0);
}
