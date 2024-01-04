/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:00:19 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 02:00:54 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    cleaner_matrix(char **matrix)
{
        int     i;

        i = -1;
        while (matrix[++i])
                free(matrix[i]);
        free(matrix);
}

void    cleaner(t_pipex *pipex, int cmds)
{
        int     i;

        i = -1;
        while (++i < cmds)
        {
                free(pipex[i].path);
                cleaner_matrix(pipex[i].cmdargs);
        }
        free(pipex);
}
