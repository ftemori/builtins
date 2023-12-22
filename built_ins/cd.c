#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	pwd(void);
int	ft_strlen(char *s);

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*path_finder(char **env)
{
	int	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp("HOME=", env[i]) == 0)
			break ;
		i++;
	}
	return (env[i]);
}

char	*path_to_usr(char *path)
{
	int	i = 0;
	while (path[i] != '/'/* || path[i] != '\0'*/)
		i++;
	return (path + i);
}

int     cd(char *path, char **env)
{
	if (!path)
	{
		path = path_finder(env);
		path = path_to_usr(path);
		
	}
        if (chdir(path) == -1)
        {
        	printf("cd: no such file or directory: %s", path);
        	return (-1);
        }
        // char    *av[2];
        // av[0] = "/usr/bin/ls";		parse it to execve
        // av[1] = NULL;
        // execve("/usr/bin/ls", av, NULL);
       // pwd();
        return (0);
}

/*int     main(int ac, char **av, char **env)
{
        char    *path = av[1];
	cd(path, env);
	return (0);
} 
*/