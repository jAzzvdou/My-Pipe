/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:04 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/18 16:51:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	closer(t_info info)
{
	close(info->pipez[0]);
	close(info->pipez[1]);
}

static char	*pathfinder(char **envp)
{
	while (*envp != NULL && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp == NULL)
		error_soft(".ERROR: Envp.\n");
	return (envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
		error_soft(".Error: Invalid number of arguments.\n");
	info.infile = open(argv[1], O_RDONLY);
	if (info.infile < 0)
		error(".ERROR: Infile.\n");
	info.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (info.outfile < 0)
		error(".ERROR: Outfile.\n");
	if (pipe(info.pipez) < 0)
		error(".ERROR: Pipe.\n");
	info.path = pathfinder(envp);
	info.commands_path = ft_split(info.path, ':');
	info.pid_one = fork();
	if (info.pid_one == 0)
		p1_child(info, argv, envp);
	info.pid_two = fork();
	if (info.pid_two == 0)
		p2_child(info, argv, envp);
	closer(&info);
	waitpid(info.pid_one, NULL, 0);
	waitpid(info.pid_two, NULL, 0);
	cleaner(&info);
	return (0);
}
