/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:44 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/18 17:46:52 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p1_child(t_info info, char **argv, char **envp)
{
	dup2(info.pipez[1], 1);
	close(info.pipez[0]);
	dup2(info.infile, 0);
	info.commands = ft_split(argv[2], ' ');
	info.command = catch_command(info.commands_path, info.commands[0]);
	if (!info.command)
	{
		error_soft()
