/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:32:17 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 02:37:24 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*aux;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while (paths[++i])
	{
		aux = ft_strjoin(paths[i], "/");
		path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	cleaner_matrix(paths);
	return (NULL);
}
