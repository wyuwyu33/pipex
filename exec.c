/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:21 by wyu               #+#    #+#             */
/*   Updated: 2022/06/27 20:21:31 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*strpdup(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s2)
		s2 = s1 + ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s2 - s1 + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1 + (++i) < s2)
		res[i] = *(s1 + i);
	res[i] = '\0';
	return (res);
}

char	*str_union(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res + s1_len, "/", 2);
	ft_strlcat(res + s1_len + 1, s2, s2_len + 1);
	return (res);
}

char	*parse_path(char *path, char *cmd)
{
	char	*colon;
	char	*res;

	colon = ft_strchr(path, ':');
	if (colon)
		path = strpdup(path, colon);
	else
		path = strpdup(path, NULL);
	if (!path)
		return (NULL);
	res = str_union(path, cmd);
	free(path);
	return (res);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*res;

	i = -1;
	while (envp[++i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		;
	if (!envp[i])
		return (cmd);
	path = envp[i] + ft_strlen("PATH=");
	while (1)
	{
		res = parse_path(path, cmd);
		if (!access(res, F_OK | X_OK))
			return (res);
		free(res);
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
