/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:32:32 by wyu               #+#    #+#             */
/*   Updated: 2022/06/23 18:33:11 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

#define INFILE	0
#define OUTFILE	1

#define STDIN 0
#define STDOUT 1

// descriptor.c
int open_file(char *filename, int file_type);
void change_standardstream(int input, int output);
int dup_pipe(int pip[2], int stream);
void redirect(char *cmd, char **envp);

// exec.c
char *parse_path(char *path, char *cmd);
char *get_path(char *cmd, char **envp);
void transform_process(char *cmd, char **envp);
#endif
