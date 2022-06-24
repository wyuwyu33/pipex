/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:44:58 by wyu               #+#    #+#             */
/*   Updated: 2022/06/24 23:48:45 by wyu              ###   ########.fr       */
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
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	perror("Wrong file_type");
	exit(1);
}

void change_standardstream(int input, int output)
{
	dup2(input, STDIN);
	dup2(output, STDOUT);
	close(input);
	close(output);
}

int dup_pipe(int fd[2], int stream)
{
	int close_fd;
	int result;

	close_fd = (stream + 1) % 2;
	close(fd[close_fd]);
	result = dup2(fd[stream], stream);
	close(fd[stream]);
	if (result == -1)
	{
		perror("dup failed");
		exit(1);
	}
	return (result);
}

void redirect(char *cmd, char **envp)
{
	int fd[2];
	int pid;

	if (pipe(fd) == -1)
	{
		perror("pipe failure");
		exit(1);
	}
	pid = fork();
	if (!pid)
	{
		dup_pipe(fd, STDOUT);
		transform_process(cmd, envp);
	}
	else
	{
		dup_pipe(fd, STDIN);
		if (wait(0) == -1)
		{
			perror("Abnormal termination of child process");
			exit(1);
		}
	}
}
