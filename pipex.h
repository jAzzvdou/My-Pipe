/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:22:16 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/15 16:24:44 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_info
{
	pid_t	pid_one;
	pid_t	pid_two;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*path;
	char	*command;
	char	**commands;
	char	**commands_path;
}	t_info;

#endif //PIPEX
