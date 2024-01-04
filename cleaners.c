/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:00:19 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 16:56:09 by jazevedo         ###   ########.fr       */
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
