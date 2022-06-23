/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:44:58 by wyu               #+#    #+#             */
/*   Updated: 2022/06/23 16:46:44 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(char *filename, int file_type)
{
	if (file_type == INFILE)
	{
		if (access(filename, F_OK | R_OK))
		{
			perror(filename);
			exit(1);
		}
		return (open(filename, O_RDONLY));
	}
	else if (file_type == OUTFILE)
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC), 0644);
	perror("Wrong file_type");
	exit(1);
}

void change_standardstream(int input, int output)
{
	dup2(input, STDIN);
	dup2(output, STDOUT);
}

int dup_pipe(int pip[2], int stream)
{
	int close_type;
	int result;

	close_type = (stream + 1) % 2;
	close(pip[close_type]);
	result = dup2(pip[stream], stream);
	close(pip[stream]);
	if (result == -1)
	{
		perror("dup failed");
		exit(1);
	}
	return (result);
}

void redirect(char *cmd, char **envp)
{
	int pip[2];
	int pid;

	if (pipe(pip) == -1)
	{
		perror("pipe failure");
		exit(1);
	}
	pid = fork();
	if (!pid)
	{
		dup_pipe(pip, STDOUT);
		transform_process(cmd, envp);
	}
	else
	{
		dup_pipe(pip, STDIN);
		if (wait(0) == -1)
		{
			perror("Abnormal termination of child process");
			exit(1);
		}
	}
}
