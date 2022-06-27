/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:21 by wyu               #+#    #+#             */
/*   Updated: 2022/06/27 17:17:43 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_path(char *path, char *cmd)
{
	char	*result;
	char	*tmp;

	result = ft_strchdup(path, ':');
	tmp = ft_strjoin(result, "/");
	free(result);
	result = ft_strjoin(tmp, cmd);
	free(tmp);
	return (result);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*result;

	i = -1;
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		;
	if (!envp[i])
		return (cmd);
	path = envp[i] + ft_strlen("PATH=");
	while (1)
	{
		result = parse_path(path, cmd);
		if (!access(result, F_OK | X_OK))
			return (result);
		free(result);
		path = ft_strchr(path, ':');
		if (!path)
			break ;
		path++;
	}
	return (cmd);
}

void	transform_process(char *cmd, char **envp)
{
	char	**argv;
	char	*filepath;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(cmd, '/'))
		filepath = argv[0];
	else
		filepath = get_path(argv[0], envp);
	execve(filepath, argv, envp);
	perror("Failed to switch process");
	exit(1);
}
