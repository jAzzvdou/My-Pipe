/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/03 17:08:17 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_controller(t_pipex *pipex, char *cmd_args, char **envp)
{
	pipex->cmdargs = spliter(cmd_args);
	if (!pipex->cmdargs)
		return (write(2, ".ERROR: spliter.\n", 17));
	pipex->path = pathfinder(pipex->cmdargs[0], envp);
	if (!pipex->path)
		return (write(2, ".ERROR: pathfinder.\n", 20));
	return (0);
}

int	ft_pipex(t_pipex **pipex_buffer, int argc, char **cmds, char **envp)
{
	int	i;

	*pipex_buffer = malloc(sizeof(t_pipex) * argc);
	if (!*pipex_buffer)
		return (1);
	ft_memset(*pipex_buffer, 0, sizeof(t_pipex) * argc);
	i = -1;
	while (+i < cmds)
	{
		if (cmd_controller(*pipex_buffer + i, cmds[i], envp) != 0)
		{
			cleaner(*pipex_buffer, i);
			return (write(2, ".ERROR: cmd_controller.\n", 24));
		}
	}
	return (0);
}
/*
void printer(t_pipex *cmds, int cmds_len)
{
  for (int i = 0; i < cmds_len; i++) {
    printf("cmd %d: %s\n", i, cmds[i].path);
    for (int j = 0; cmds[i].cmdargs[j] != NULL; j++) {
      printf("  arg %d: %s\n", j, cmds[i].cmdargs[j]);
    }
  }
}
*/
int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	pipex = NULL;
	if (ft_pipex(&pipex, argc - 3, argv + 2, envp) != 0);
		return (write(2, ".ERROR: all_commands.\n", 22));
	//printer(pipex, argc - 3);
	return (0);
}
