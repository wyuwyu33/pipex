/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:17:21 by wyu               #+#    #+#             */
/*   Updated: 2022/06/22 19:23:27 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

#define INFILE	0
#define OUTFILE	1

#define STDIN 0
#define STDOUT 1

int open_file(char *file_name, int file_type)
{
	if (file_type == INFILE)
	{
		if (access(file_name, F_OK | R_OK))
		{
			perror(file_name);
			exit(1);
		}
		return (open(file_name, O_RDONLY));
	}
	else if (file_type == OUTFILE)
		return (open(file_name, O_WRONLY | O_CREAT | O_TRUNC), 0644);
	perror("Wrong file_type");
	exit(1);
}

void change_standardstream(int input, int output)
{
	dup2(input, STDIN);
	dup2(output, STDOUT);
}

void get_path(char *cmd, char *envp[])
{
	int i;
	char *path;
	char *dir;

	i = -1;
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")));
	if (!envp[i])
		return (cmd);
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

void transform_process(char *cmd, char *envp[])
{

}

void redirect(char *cmd, char *envp[])
{
	int pip[2];
	int pid;

	if (pipe(pip) == -1)
	{
		perror("pipe failure");
		exit(1);
	}
	pid = fork();
	if (!pip)
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

int main(int argc, char *argv[], char *envp[])
{
	int infile;
	int outfile;

	if (argc != 5)
	{
		perror("Argument error");
		return (1);
	}
	infile = open_file(argv[1], INFILE);
	outfile = open_file(argv[4], OUTFILE);
	change_standardstream(infile, outfile);
	redirect(argv[2], envp);
	transform_process(argv[3], envp);
	perror("Do not perform function");
	return (1);
}
