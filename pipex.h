/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 16:56:28 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid;
	int	pipe[2];
	int	fd[2];
	char	*path;
	char	**cmdargs;
	char	**envi;
}	t_pipex;

//----------PIPEX----------//
int	main(int argc, char **argv, char **envp);
char	**spliter(char *cmd);
char    *pathfinder(t_pipex *pipex);

//----------CLEANER----------//
void	cleaner_matrix(char **matrix);

//----------QUOTE----------//
int	verify_quote(char *cmd, int i);
int	is_quote(char *cmd, int i);

//----------UTILS----------//


#endif //PIPEX
