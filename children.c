/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:44 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/21 15:41:04 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*catch_cmd(char **path, char *cmd)
{
	char	*temp;
	char	*the_cmd;

	while (*path)
	{
		if (access(cmd, 0) == 0)
			return (cmd);
		temp = ft_strjoin(*path, "/");
		the_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(the_cmd, 0) == 0)
			return (the_cmd);
		free(the_cmd);
		path++;
	}
	return (NULL);
}

void	p1_child(t_info info, char **argv, char **envp)
{
	dup2(info.pipes[1], 1);
	close(info.pipes[0]);
	dup2(info.infile, 0);
	info.cmds = ft_split(argv[2], ' ');
	info.cmd = catch_cmd(info.cmd_path, info.cmds[0]);
	if (!info.cmd)
	{
		write(2, "ERROR: Command not found.", 25);
		cleaner_child(&info);
		exit(1);
	}
	execve(info.cmd, info.cmds, envp);
}

void	p2_child(t_info info, char **argv, char **envp)
{
	dup2(info.pipes[0], 0);
	close(info.pipes[1]);
	dup2(info.infile, 1);
	info.cmds = ft_split(argv[3], ' ');
	info.cmd = catch_cmd(info.cmd_path, info.cmds[0]);
	if (!info.cmd)
	{
		write(2, "ERROR: Command not found.", 25);
		cleaner_child(&info);
		exit(1);
	}
	execve(info.cmd, info.cmds, envp);
}
