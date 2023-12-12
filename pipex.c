/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:04 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/12 16:06:39 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	exec(char **envp, t_command command)
{
	pid_t	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		return (-1);
	if else (pid == 0)
	{
		dup2(0, command->input);
		close(command->input);
		dup2(1, command->output);
		close(command->output);
		execve(command->args[0], command->args, envp);
		ft_printf("se fudeu deu errado otario");
		return (0);
	}
}

executor()
{
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		executor(argc, argvs);
	else
		ft_printf("ERROR! USAGE: ./pipex file1 cmd1 cmd2 file2");
	return (0);
}

