/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:17:21 by wyu               #+#    #+#             */
/*   Updated: 2022/06/27 17:21:03 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

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
