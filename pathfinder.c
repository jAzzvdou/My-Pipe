#include "pipex.h"

char	*pathfinder(t_pipex *pipex)
{
	int		i;
	int		ii;
	char	**paths;
	char	*path;
	char	*aux;

	if (my_strchr(pipex->cmdargs[0], '/'))
		return (pipex->cmdargs[0]);
	ii = 0;
	while (my_strncmp(pipex->envi[ii], "PATH=", 5))
		ii++;
	paths = my_split(pipex->envi[ii] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		aux = my_strjoin(paths[i], "/");
		path = my_strjoin(aux, pipex->cmdargs[0]);
		free(aux);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	cleaner_matrix(paths);
	return (NULL);
}
