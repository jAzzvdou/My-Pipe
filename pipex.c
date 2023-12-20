/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:04 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/20 17:09:14 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	closer(t_info info)
{
	close(info->pipes[0]);
	close(info->pipes[1]);
}

static char	*pathfinder(char **envp)
{
	while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp == NULL)
		error_write(".ERROR: Envp.\n");
	return (envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
		error_write(".Error: Invalid number of arguments.\n");
	info.infile = open(argv[1], O_RDONLY);
	if (info.infile < 0)
		error_perror(".ERROR: Infile.\n");
	info.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (info.outfile < 0)
		error_perror(".ERROR: Outfile.\n");
	if (pipe(info.pipes) < 0)
		error_perror(".ERROR: Pipe.\n");
	info.path = pathfinder(envp);
	info.cmd_path = ft_split(info.path, ':');
	info.p1 = fork();
	if (info.p1 == 0)
		p1_child(info, argv, envp);
	info.p2 = fork();
	if (info.p2 == 0)
		p2_child(info, argv, envp);
	closer(&info);
	waitpid(info.p1, NULL, 0);
	waitpid(info.p2, NULL, 0);
	cleaner(&info);
	return (0);
}
